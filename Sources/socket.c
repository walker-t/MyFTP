/*
** socket.c for socket in /home/lofo/Taf/PSURéseau/my_ftp
** 
** Made by Tom
** Login   <tom.walker@epitech.eu>
** 
** Started on  Sat May 20 20:39:24 2017 Tom
** Last update Sun May 21 17:57:02 2017 Tom
*/

#include "ftp.h"

int		create_socket(int port)
{
  int			fd;
  struct sockaddr_in	server;
  struct protoent	*pe;

  if (!(pe = getprotobyname("TCP")))
    return (-1);
  if ((fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    return (-1);
  if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int)) < 0)
    return (-1);
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(port);
  if (bind(fd, (const struct sockaddr *)&server, sizeof(server)) == -1)
    {
      if (close(fd) == -1)
	return (-1);
      return (-1);
    }
  return (fd);
}

void		listen_socket(int s_serveur)
{
  int			client_size;
  int			client_fd;
  struct sockaddr_in	client;

  listen(s_serveur, 10);
  printf("[+] Waiting for incoming connections...\n");
  while (1)
    {
      client_size = sizeof(client);
      if ((client_fd = accept(s_serveur, (struct sockaddr *)&client, (socklen_t *)&client_size)) == -1)
	{
	  write (2, "[-] Connection failed\n", 21);
	  return;
	}
      if (!(fork()))
	{
	  close(s_serveur);
	  handle_client(client_fd);
	  exit(EXIT_SUCCESS);
	}
      else
	{
	  close(client_fd);
	}
    }
}
