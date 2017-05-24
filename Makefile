##
## Makefile for MYFTP in /home/lofo/Taf/PSURéseau/PSU_2016_myftp
## 
## Made by Tom
## Login   <tom.walker@epitech.eu>
## 
## Started on  Sun May 21 17:37:15 2017 Tom
## Last update Sun May 21 17:54:17 2017 Tom
##

SRCS		= 	Sources/get_next_line.c \
			Sources/main.c	\
			Sources/my_str_to_wordtab.c \
			Sources/socket.c \
			Sources/guest.c	\
			Sources/usercmd.c

OBJS		=	$(SRCS:.c=.o)

CFLAGS		=	-W -Wextra -Wall -Werror -I./Includes/

CC		=	gcc

RM		=	rm -rf

NAME		=	server

all:			$(NAME)

$(NAME):		$(OBJS)
			$(CC) -o $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
