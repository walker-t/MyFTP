/*
** main.c for main in /home/walker/Taf/RéseauPSU/Cours
** 
** Made by Walker
** Login   <tom.walker@epitech.eu>
** 
** Started on  Thu May 11 16:41:41 2017 Walker
** Last update Sun May 21 17:55:18 2017 Tom
*/

#include "ftp.h"

int		error()
{
  printf("Usage: ./serveur port path\n");
  return (-1);
}

int		nice_close(int fd)
{
  if (close(fd) == -1)
    return (-1);
  return (-1);
}

int		get_port(char *av)
{
  int		port;

  port = atoi(av);
  if (port > 65535)
    return (-1);
  return (port);
}

int		main(int ac, char **av)
{
  int		port;
  int		socket;
  char		*path;

  if (ac < 3 || (port = get_port(av[1])) == -1)
    return (error());
  if ((path = av[2]) && chdir(path) == -1)
    return (error());
  if ((socket = create_socket(port)) == -1)
    return (-1);
  listen_socket(socket);
  return (0);
}
