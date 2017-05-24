/*
** my_str_to_wordtab.c for my_str_towordtab in /home/lofo/Taf/PSURéseau/my_ftp
** 
** Made by Tom
** Login   <tom.walker@epitech.eu>
** 
** Started on  Sun May 21 00:45:33 2017 Tom
** Last update Sun May 21 00:50:47 2017 Tom
*/

#include "ftp.h"
#include <stdlib.h>
#include <string.h>

void	my_exit(char *str)
{
  printf("%s\n", str);
  exit (EXIT_FAILURE);
}

int	tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      free (tab[i]);
      i++;
    }
  free (tab);
}

int	count_word(char *str, char separe)
{
  int	i;
  int	count;

  i = 0;
  count = 1;
  while (str[i] == ' ' || str[i] == '\t' || str[i] == separe)
    i++;
  while (str[i])
    {
      if (str[i] == ' ' || str[i] == '\t' || str[i] == separe)
	{
	  while (str[i] == ' ' || str[i] == '\t' || str[i] == separe)
	    i++;
	  if (str[i])
	    count++;
	}
      if (str[i])
	i++;
    }
  return (count);
}

char	**my_str_to_wordtab(char *str, char separe)
{
  char	**tab;
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  if ((tab = malloc(sizeof(*tab) * ((count_word(str, separe) + 1)))) == NULL)
    my_exit("Malloc() fail.");
  while (str[i] == '\t' || str[i] == ' ' || str[i] == separe)
    i++;
  while (str[i])
    {
      if ((tab[j] = malloc(sizeof(**tab) * (strlen(str) + 1))) == NULL)
	my_exit("Malloc() fail.");
      k = 0;
      while (str[i] != ' ' && str[i] != '\t' && str[i] != separe && str[i])
	tab[j][k++] = str[i++];
      tab[j++][k] = '\0';
      while (str[i] == ' ' || str[i] == '\t' || str[i] == separe)
	i++;
    }
  tab[j] = NULL;
  return (tab);
}
