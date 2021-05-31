##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile root matchstick
##

SRC	= 	src/main.c	\
		src/gameplay.c	\
		src/check_nb.c	\
		src/turn.c

OBJ	= 	${SRC:.c=.o}

NAME	= 	matchstick

CFLAGS	= 	-W -Wall -Wextra

CPPFLAGS= 	-I./include

LDFLAGS	= 	-L./lib -lmy

all:	binairy test_run

libmy:
	make -C lib/

test_run:
	make -C tests/

binairy: libmy $(OBJ)
	gcc -o $(NAME) $(CFLAGS) $(SRC) $(LDFLAGS) $(CPPFLAGS)

clean:
	make -C lib/ clean
	make -C tests/ clean
	rm -f $(OBJ)

fclean: clean
	make -C lib/ fclean
	make -C tests/ fclean
	rm -f $(NAME)
	clear

re: fclean all

.PHONY: clean fclean re all libmy binairy test_run
