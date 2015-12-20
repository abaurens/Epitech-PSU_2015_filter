##
## Makefile for filter in /home/bauren_a/Work/tek-1/PSU_year_filter
## 
## Made by Arthur
## Login   <bauren_a@epitech.net>
## 
## Started on  Tue Dec 15 16:06:37 2015 Arthur
## Last update Sun Dec 20 03:21:13 2015 Arthur
##

SRC	=	str.c		\
		string.c	\
		int_format.c	\
		str_format.c	\
		char_format.c	\
		filter.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

INCLUDE	=	./include/

CFLAGS	+=	-I$(INCLUDE)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rs $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re

