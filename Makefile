##
## Makefile for  in /home/januar_m/delivery/CPool_Day10/lib/my
## 
## Made by Martin Januario
## Login   <januar_m@epitech.net>
## 
## Started on  Fri Oct 14 09:55:01 2016 Martin Januario
## Last update Tue Dec  6 13:30:33 2016 
##

SRC	=	SRC/main.c		\
		SRC/my_strcat.c		\
		SRC/my_strdup.c		\
		SRC/my_getnbr.c		\
		SRC/make_obs.c		\
		SRC/my_strcpy.c		\
		SRC/my_strncpy.c	\
		SRC/bsq.c		\
		SRC/disp_tab.c		\
		SRC/free_tab.c		\
		SRC/make_tab.c		\
		SRC/my_strlen.c		\
		SRC/my_putstr.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g -I include/

NAME	=	bsq

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
