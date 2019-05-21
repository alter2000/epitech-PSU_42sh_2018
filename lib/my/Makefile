##
## EPITECH PROJECT, 2018
## CPool_Day07_2018
## File description:
## libmy makefile
##

CFLAGS=-Wall -Werror -I./ -I./my_printf
DFLAGS=-Wall -I./ -I./my_printf
SRC=$(shell find . -type f -name '*.c')
OBJ=$(SRC:.c=.o)

all: link

link: $(OBJ) ./my.h
	@ar rcs libmy.a $(OBJ)
	@mkdir -p ../../include
	@cp -f ./libmy.a ../libmy.a
	@cp -f ./my.h ../../include/my.h

debug: $(SRC) ./my.h
	@gcc -c -g $(SRC) $(DFLAGS)
	@ar rcs libmy.a $(OBJ)
	@mkdir -p ../../include
	@cp -f ./libmy.a ../libmy.a
	@cp -f ./my.h ../../include/my.h

clean:
	@rm -f $(OBJ) ./libmy.a ../libmy.a

fclean: clean
	# @rm -f ../../include/my.h

../../include/my.h: ./my.h
	cp -f $< $@

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all obj link clean fclean re debug
