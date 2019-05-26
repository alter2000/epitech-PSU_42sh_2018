/*
** EPITECH PROJECT, 2019
** PSU_minishell_2018
** File description:
** something small
*/

#ifndef TYPESHELL_H
    #define TYPESHELL_H

    #include <fcntl.h>
    #include <stdbool.h>
    #include <stddef.h>
    #include <stdio.h>

    #define DEFAULT_PATH ((char *[]) \
            {"setenv", "PATH", "/bin:/usr/bin:/usr/local/bin:/usr/sbin", 0})

typedef enum MYSHTOK {
    T_EXPR = -1,
    T_SEMICOLON = 0,
    T_BINOP_AND = 1,
    T_BINOP_OR = 2,
    T_JOB_BG = 3,
    T_PIPE = 4,
    T_REDIR_OUT_APPEND = 5,
    T_REDIR_ERR_APPEND = 6,
    T_REDIR_AMP_APPEND = 7,
    T_REDIR_APPEND = 8,
    T_REDIR_OUT = 9,
    T_REDIR_ERR = 10,
    T_REDIR_AMP = 11,
    T_REDIR = 12,
    T_REDIR_IN_APPEND = 13,
    T_REDIR_IN = 13,
    /*
        T_QUOTE = 14,
        T_DQUOTE = 15,
        T_BACKTICK = 16,
    */
} token_t;

static const char * const MYSHTOK_LIST[] = {
    ";",
    "&&",
    "||",
    "&",
    "|",
    "1>>",
    "2>>",
    ">>&",
    ">>",
    "1>",
    "2>",
    ">&",
    ">",
    "<<",
    "<",
    NULL
};

static const char * const EXPR_SEMICOLON[] = {
    ";",
    NULL
};

static const char * const EXPR_BINOP[] = {
    "&&",
    "||",
    NULL
};

static const char * const EXPR_BG[] = {
    "&",
    NULL
};

static const char * const EXPR_REDIR_OUT[] = {
    "|",
    "1>>",
    "2>>",
    ">>&",
    ">>",
    "1>",
    "2>",
    ">&",
    ">",
    NULL
};

static const char * const EXPR_REDIR_IN[] = {
    "<<",
    "<",
    NULL
};

static const char * const * const EXPR_TOKENS[] = {
    EXPR_SEMICOLON,
    EXPR_BINOP,
    EXPR_BG,
    EXPR_REDIR_OUT,
    EXPR_REDIR_IN,
    0
};

enum cmd_state {
    STATE_QUOTE,
    STATE_DQUOTE,
    STATE_ESEQ,
    STATE_GENERAL,
};

typedef struct dict {
    struct dict *next;
    char *k;
    char *v;
} dict_t;

typedef struct job {
    char *cmd;
    int pid;
    struct job *next;
    struct job *prev;
} job_t;

typedef struct joblist {
    struct joblist *first;
    struct joblist *last;
    int cnt;
} joblist_t;

typedef struct sh {
    dict_t *env;
    dict_t *shvar;
    dict_t *alias;
    FILE *infd;
    FILE *outfd;
    FILE *errfd;
    unsigned char exc;
    bool eof;
    bool showtree;
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
    cmd_t *cmd;
    struct ast *left;
    struct ast *right;
} ast_t;

#endif
