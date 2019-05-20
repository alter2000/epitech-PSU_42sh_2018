##
## EPITECH PROJECT, 2018
## CPool_Day07_2018
## File description:
## standard makefile
##

NAME=42sh
CFLAGS+= -Werror -Wall -I./include -L./lib/my -lmy
DFLAGS+= -Wall -I./include -L./lib/my -lmy -g
DFLAGS+= -fsanitize=address
SRC=$(wildcard ./*.c)
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) ./include/my.h ./include/typeshell.h ./include/shell.h
	@$(MAKE) -C ./lib/my
	@gcc -o $(NAME) $(OBJ) $(CFLAGS)

debug: $(SRC) ./include/my.h ./include/typeshell.h ./include/shell.h
	@$(MAKE) -C ./lib/my debug
	clang -o $(NAME) $(SRC) $(DFLAGS)

clean:
	@rm -f $(OBJ) $(shell find . -name '*.gc*' -o -name 'vgcore.*')
	@$(MAKE) -C ./lib/my clean

fclean: clean
	@rm -f $(NAME) unit_tests
	@$(MAKE) -C ./lib/my fclean

re:
	@$(MAKE) fclean
	@$(MAKE) all

./include/my.h: ./lib/my/my.h
	cp -f $< $@

.PHONY: all debug clean fclean re
