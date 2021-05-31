##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile lib matchstick
##

SRC	=	error_handling.c	\
		map.c			\
		my_getnbr.c		\
		my_putstr.c		\
		my_strlen.c		\
		my_put_nbr.c		\
		my_putchar.c

OBJ	= 	${SRC:.c=.o}

NAME	= 	libmy.a

all:	libmy

libmy: $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all libmy
