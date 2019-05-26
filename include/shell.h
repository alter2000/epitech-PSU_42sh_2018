/*
** EPITECH PROJECT, 2019
** PSU_minishell_2018
** File description:
** something small
*/

#ifndef SHELL_H
    #define SHELL_H

    #include <signal.h>
    #include <sys/wait.h>
    #include "my.h"
    #include "typeshell.h"

    #define SHELL_PS1 ("> ")

/* Dictionary manipulation */
dict_t *mkdict(char **);
void rmdict(dict_t *);
char *dict_get(dict_t *, char const *);
char *dict_pop(dict_t **, char const *);
dict_t *dict_push(dict_t *, char *, char *);

/* Builtins */
int cmd_setenv(int, char **, sh_t *);
int cmd_unsetenv(int, char **, sh_t *);
int cmd_env(int, char **, sh_t *);
int cmd_cd(int, char **, sh_t *);
int cmd_exit(int, char **, sh_t *);
int cmd_alias(int, char **, sh_t *);
int cmd_unalias(int, char **, sh_t *);
int cmd_jobs(int, char **, sh_t *);

/* Builtin helpers */
int change_cwd(sh_t *, char *);
int cmd_exec(cmd_t *);
char *get_path(char *, dict_t *);
void eval_aliases(ast_t *, dict_t *);

/* Environment */
char *env_get_key(char const *);
char *env_get_val(char const *);
size_t env_len(dict_t *);
char **env_to_tab(dict_t *);

/* Miscellaneous */
ast_t *prompt(sh_t *);
bool setenv_is_sane(char const *);
int sh_setexc(sh_t *, int);
int noninteractive(int, char **, sh_t *);
int loop(sh_t *);
void infile(char *, sh_t *);
void rmsh(sh_t *);

/* All parsing functions */

/* AST build/teardown */
ast_t *mknode(void);
ast_t *mkast(char *, sh_t *);
ast_t *rmast(ast_t *);
ast_t *parse(ast_t *);
bool token(ast_t *, char const * const *);

char *next_tok(char **, char const *);

/* Single commands */
cmd_t *mkcmd(sh_t *, char **);
void rmcmd(cmd_t *);
bool cmd_builtins(cmd_t *, cmd_t const *);

/* Parsing single-use functions */

int parse_out_append(ast_t *, ast_t *);
int parse_err_append(ast_t *, ast_t *);
int parse_amp_append(ast_t *, ast_t *);
int parse_append(ast_t *, ast_t *);
int parse_in_append(ast_t *, ast_t *);

int parse_semicolon(ast_t *, ast_t *);
int parse_and(ast_t *, ast_t *);
int parse_or(ast_t *, ast_t *);
int parse_job_bg(ast_t *, ast_t *);
int parse_pipe(ast_t *, ast_t *);

int parse_err(ast_t *, ast_t *);
int parse_amp(ast_t *, ast_t *);
int parse_out_simple(ast_t *, ast_t *);
int parse_out(ast_t *, ast_t *);
int parse_in(ast_t *, ast_t *);

static inline bool esc(char *str, int idx)
{
    return idx > 0 && str[idx - 1] == '\\';
}

static const cmd_t BUILTINS[] = {
    { "setenv",   cmd_setenv,   0, 0, 0 },
    { "unsetenv", cmd_unsetenv, 0, 0, 0 },
    { "env",      cmd_env,      0, 0, 0 },
    { "cd",       cmd_cd,       0, 0, 0 },
    { "exit",     cmd_exit,     0, 0, 0 },
    { "alias",    cmd_alias,    0, 0, 0 },
    { "unalias",  cmd_unalias,  0, 0, 0 },
    { "jobs",     cmd_jobs,     0, 0, 0 },
    { 0, 0, 0, 0, 0 }
};

static int (* const PARSE_TOKEN[])(ast_t *left, ast_t *right) = {
    parse_semicolon,
    parse_and,
    parse_or,
    parse_job_bg,
    parse_pipe,
    parse_out_append,
    parse_err_append,
    parse_amp_append,
    parse_append,
    parse_out,
    parse_err,
    parse_amp,
    parse_out_simple,
    parse_in_append,
    parse_in,
};

#endif
