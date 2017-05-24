/*
** get_next_line.h for getnextline in /home/lofo/Taf/PSURéseau/my_ftp
** 
** Made by Tom
** Login   <tom.walker@epitech.eu>
** 
** Started on  Sun May 21 12:17:54 2017 Tom
** Last update Sun May 21 18:06:14 2017 Tom
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct		s_stack
{
  char			value;
  struct s_stack	*next;
}			t_stack;

char	*get_next_line(const int);

#endif /* !GET_NEXT_LINE_H_ */
