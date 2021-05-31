##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile root matchstick
##

SRC	= 	\

OBJ	= 	${SRC:.c=.o}

NAME	= 	unit_test

CFLAGS	= 	-W -Wall -Wextra

UTFLAGS	=	--coverage -lcriterion

CPPFLAGS= 	-I./../include

LDFLAGS	= 	-L./../lib -lmy

all:	test_run

libmy:
	make -C ../lib/

test_run: libmy $(OBJ)
	gcc -o $(NAME) $(CFLAGS) $(SRC) $(LDFLAGS) $(CPPFLAGS) $(UTFLAGS)
	./unit_test

clean:
	make -C ../lib/ clean
	rm -f $(OBJ)

fclean: clean
	make -C ../lib/ fclean
	rm -f $(NAME)
	clear

re: fclean all

.PHONY: clean fclean re all libmy test_run
