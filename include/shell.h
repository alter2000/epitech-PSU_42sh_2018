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

/* Single commands */
cmd_t *mkcmd(sh_t *, char **);
void rmcmd(cmd_t *);
bool cmd_builtins(cmd_t *, cmd_t const *);


static inline bool esc(char *str, int idx)
{
    return idx > 0 && str[idx - 1] == '\\';
}

#endif
