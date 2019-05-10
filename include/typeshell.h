/*
** EPITECH PROJECT, 2019
** PSU_minishell_2018
** File description:
** something small
*/

#ifndef TYPESHELL_H
    #define TYPESHELL_H

    #include <stddef.h>
    #include <stdbool.h>

    #define FOREACH_TOKEN(TOK) \
        TOK(SEQ) \
        TOK(QUOTE) \
        TOK(DQUOTE) \
        TOK(PIPE) \
        TOK(REDIR) \
        TOK(REDIR_A) \
        TOK(SEMICOLON) \
        TOK(WHILE) \
        TOK(FOR) \
        TOK(IF) \
        TOK(COLON) \

    #define GEN_TOKEN(ENUM) ENUM,
    #define STR(STRING) #STRING,
    #define XSTR(STRING) STR(STRING)

enum MYSH_TOKEN {
    FOREACH_TOKEN(GEN_TOKEN)
};
typedef enum MYSH_TOKEN token_t;

typedef struct dict {
    struct dict *next;
    char *k;
    char *v;
} dict_t;

typedef struct redir {
    int in[2];
    int out[2];
    int err[2];
} redir_t;

typedef struct sh {
    dict_t *env;
    redir_t fdt;
    unsigned char exc;
    bool eof;
} sh_t;

typedef struct cmd {
    char *name;
    int (*func)(int, char **, sh_t *);
    sh_t *sh;
    char **av;
    int ac;
} cmd_t;

typedef struct item {
    size_t begin;
    size_t end;
    token_t type;
    char *name;
} item_t;

typedef struct ast {
    token_t type;
    char *name;
    struct ast *left;
    struct ast *right;
} ast_t;

#endif
