##
## EPITECH PROJECT, 2018
## CPool_Day07_2018
## File description:
## standard makefile
##

NAME=42sh
CFLAGS+= -Werror -Wall -I./include
LDFLAGS= -L./lib/my -lmy

DFLAGS+= -Wall -I./include -L./lib/my -lmy -g
# DFLAGS+= -fsanitize=address

SRC= ./main.c ./path.c ./progflow.c ./dict.c \
	./builtins/aliases.c ./builtins/bi_env.c ./builtins/cd.c \
	./builtins/env.c ./builtins/jobs.c \
	./cmd/cmd.c ./cmd/exec_cmd.c \
	./lexer/ast_cons.c ./lexer/ast_destr.c ./lexer/token.c ./lexer/syntax.c \
	./lexer/helpers_token.c ./lexer/set_cmds.c \
	./parser/infile.c ./parser/parse.c ./parser/parse_append.c \
	./parser/parse_binop.c ./parser/parse_last.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) ./include/my.h ./include/typeshell.h ./include/shell.h
	@$(MAKE) -C ./lib/my
	@gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

debug: $(SRC) ./include/my.h ./include/typeshell.h ./include/shell.h
	@$(MAKE) -C ./lib/my debug
	clang -o $(NAME) $(SRC) $(DFLAGS)

clean:
	@rm -f $(shell find . -name '*.gc*' -o -name 'vgcore.*' -o -name '*.o')
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
