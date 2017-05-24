/*
** ftp.h for ftp in /home/walker/Taf/RéseauPSU/Cours/server
** 
** Made by Walker
** Login   <tom.walker@epitech.eu>
** 
** Started on  Wed May 17 20:14:46 2017 Walker
** Last update Sun May 21 17:56:36 2017 Tom
*/

#ifndef FTP_H_
#define FTP_H_

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "get_next_line.h"

typedef struct	s_client
{
  char			*user;
  char			*passwd;
  int			fd;
  int			log;
  int			client_fd;
}		t_client;

char    **my_str_to_wordtab(char *str, char separe);
int	nice_close(int fd);
int	init(int port);
int	accept_client(int fd);
void	handle_client(int client_fd);
int	user_check(int fd, char *cmd);
void	login(t_client *client, char *login);
void	pass(t_client *client, char *pass);
int     create_socket(int port);
void    listen_socket(int s_serveur);
void    get_pwd(t_client *client);
  
#endif /* !FTP_H_ */
