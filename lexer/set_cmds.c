/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** something small
*/

#include "shell.h"

bool set_cmds(ast_t *ast, sh_t *sh)
{
    if (ast->left && !set_cmds(ast->left, sh))
        return false;
    if (ast->right && !set_cmds(ast->right, sh))
        return false;
    if (ast->type == T_EXPR) {
        ast->cmd = mkcmd(sh, str_to_tab(ast->name, " \t\n"));
    }
    return true;
}
