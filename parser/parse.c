/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** something small
*/

#include "shell.h"

int parse(ast_t *ast, sh_t *sh)
{
    if (!ast)
        return 0;
    if (ast->type != T_EXPR)
        return PARSE_TOKEN[ast->type](sh, ast->left, ast->right);
    else {
        if (!cmd_builtins(ast->cmd, BUILTINS) && ast->cmd->ac)
            cmd_exec(ast->cmd);
    }
    return 1;
}
