##
## Makefile for bsq in /home/rieux-_t/Documents/rendu/Elem/CPE_2014_bsq
## 
## Made by thomas rieux-laucat
## Login   <rieux-_t@epitech.net>
## 
## Started on  Thu Jan 15 16:46:19 2015 thomas rieux-laucat
## Last update Tue Jan 20 23:29:13 2015 thomas rieux-laucat
##

CC      =       gcc -g

RM      =       rm -f

CFLAGS  +=      -W -Wextra -Wall
CFLAGS  +=      -pedantic

NAME    =       bsq

SRCS    =       base_fonction.c \
		my_fonction.c \
		get_next_line.c \
		my_getnbr.c \
		algo2.c \
		algo.c \
		main.c

OBJS    =       $(SRCS:.c=.o)

all     :       $(NAME)

$(NAME) :       $(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean   :
		$(RM) $(OBJS)

fclean  :       clean
		$(RM) $(NAME)

re      :       fclean all

.PHONY  :       all clean fclean re
