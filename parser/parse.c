/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** something small
*/

#include "shell.h"

ast_t *parse(ast_t *ast)
{
    if (!ast)
        return 0;
    if (!cmd_builtins(ast->cmd, BUILTINS) && ast->cmd->ac)
        cmd_exec(ast->cmd);
    return ast;
}
