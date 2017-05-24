/*
** guest.c for guest in /home/lofo/Taf/PSURéseau/my_ftp
** 
** Made by Tom
** Login   <tom.walker@epitech.eu>
** 
** Started on  Sat May 20 21:05:06 2017 Tom
** Last update Sun May 21 17:57:28 2017 Tom
*/

#include "ftp.h"

void		delete(t_client *client)
{
  free(client->user);
  free(client->passwd);
  free(client);
}

char		*get_cmd(int fd)
{
  char		*cmd;

  cmd = get_next_line(fd);
  if (cmd[strlen(cmd) - 1] == '\r')
    cmd[strlen(cmd) - 1] = 0;
  return (cmd);
}

void		other_cmd(t_client *client, char *cmd)
{
  (void)cmd;
  dprintf (client->client_fd, "%d %s\r\n", 100, "Command not implement yet.");
}


void		wait_input(t_client *client)
{
  char		*cmd;
  char		**final_cmd;

  while ((cmd = get_cmd(client->client_fd)) != NULL
	 && strcmp(cmd, "QUIT")
	 && (final_cmd = my_str_to_wordtab(cmd, ' ')) != NULL)
    {
      printf("Client \"%d\" send: \"%s\"\n", client->client_fd, cmd);
      if (final_cmd[0] && !strcmp("USER", final_cmd[0]))
	login(client, final_cmd[1]);
      else if (final_cmd[0] && !strcmp("PASS", final_cmd[0]))
	pass(client, final_cmd[1]);
      else if (client->log == 0)
	dprintf (client->client_fd, "%d %s\r\n", 530, "Permission denied.");
      else if (final_cmd[0] && !strcmp("PWD", final_cmd[0]) && client->log == 1)
	get_pwd(client);
      else
	other_cmd(client, final_cmd[0]);
      free(cmd);
      free(final_cmd);
    }
}

void		handle_client(int client_fd)
{
  t_client	*client;

  write(1, "[+] Connection accepted\n", 24); 
  dprintf(client_fd, "%d %s\r\n", 220, "Hello.");
  client = malloc(sizeof(t_client));
  client->user = NULL;
  client->passwd = NULL;
  client->client_fd = client_fd;
  wait_input(client);
  delete(client);
  dprintf(client_fd, "%d %s\r\n", 221, "Goodbye.");
  printf("[-] Connection ended\n");
}
