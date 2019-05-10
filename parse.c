/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** something small
*/

#include "shell.h"

static const cmd_t builtins[] = {
    { "setenv",   cmd_setenv,   0, 0, 0 },
    { "unsetenv", cmd_unsetenv, 0, 0, 0 },
    { "env",      cmd_env,      0, 0, 0 },
    { "cd",       cmd_cd,       0, 0, 0 },
    { "exit",     cmd_exit,     0, 0, 0 },
    { "alias",    cmd_alias,    0, 0, 0 },
    { "unalias",  cmd_unalias,  0, 0, 0 },
    { 0, 0, 0, 0, 0 }
};

ast_t *mkast(char *s, sh_t *sh)
{
    ast_t *ast = gib(sizeof(*ast));

    ast->cmd = mkcmd(sh, str_to_tab(s, " \t\n"));
    return ast;
}

ast_t *parse(ast_t *ast)
{
    if (!cmd_builtins(ast->cmd, builtins) && ast->cmd->ac)
        cmd_exec(ast->cmd);
    rmcmd(ast->cmd);
    return 0;
}

void rmast(ast_t *s)
{
    (void)s;
}
