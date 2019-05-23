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
    { "jobs",     cmd_jobs,     0, 0, 0 },
    { 0, 0, 0, 0, 0 }
};

ast_t *parse(ast_t *ast)
{
    if (!ast)
        return 0;
    if (!cmd_builtins(ast->cmd, builtins) && ast->cmd->ac)
        cmd_exec(ast->cmd);
    return ast;
}
