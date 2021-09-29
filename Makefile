##
## EPITECH PROJECT, 2020
## makefile exe
## File description:
## fct
##

SRC	=	$(wildcard *.c)

CFLAGS	=	-W -Wextra -Wall -Werror -g3

LFLAGS	=	-L lib/ -lmy

IFLAGS	=	-I include/

NAME	=	navy

all:
	make -C lib/my all
	gcc -o $(NAME) $(SRC) $(IFLAGS) $(LFLAGS) $(CFLAGS)
	mkdir tmp
	touch tmp/pid_user2
	touch tmp/map_user1
	touch tmp/map_user2

clean:
	make -C lib/my clean
	rm -f *~
	rm -f *.o
	rm -r tmp

fclean:
	make -C lib/my fclean
	rm -f $(NAME)
	rm -r tmp

re:	fclean all
	make -C lib/my re
