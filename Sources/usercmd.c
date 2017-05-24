/*
** usercmd.c for usercmd in /home/lofo/Taf/PSURéseau/my_ftp
** 
** Made by Tom
** Login   <tom.walker@epitech.eu>
** 
** Started on  Sat May 20 23:34:41 2017 Tom
** Last update Sun May 21 17:57:55 2017 Tom
*/

#include "ftp.h"

void   login(t_client *client, char *login)
{
  if (client->log == 1)
    dprintf (client->client_fd, "%d %s\r\n", 530, "Can't change user."); 
  else if (login)
    {
      client->user = strdup(login);
      dprintf (client->client_fd, "%d %s\r\n", 331, "User name okay, need password."); 
    }
  else
    dprintf (client->client_fd, "%d %s\r\n", 332, "A login is required."); 
}

void	get_pwd(t_client *client)
{
  char	*path;

  if ((path = getcwd(0, 0)) == NULL)
    dprintf(client->client_fd, "%d %s\r\n", 450, "Failed to get PWD.");
  else
    dprintf(client->client_fd, "%d %s\r\n", 257, path);
}

void	pass(t_client *client, char *passwd)
{
  if (client->log == 1)
    dprintf (client->client_fd, "%d %s\r\n", 230, "Already logged in."); 
  else if (client->user == NULL)
    dprintf (client->client_fd, "%d %s\r\n", 332, "A login is required."); 
  else if ((!strcmp("Anonymous", client->user)
       || !(strcmp("anonymous", client->user)))
      && passwd == NULL)
    {
      free(client->user);
      client->user = NULL;
      client->log = 1;
      dprintf (client->client_fd, "%d %s\r\n", 230, "User logged in, proceed.");
    }
  else
    dprintf (client->client_fd, "%d %s\r\n", 331, "Wrong password.");
}
