/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** something small
*/

#include "shell.h"

ast_t *rmast(ast_t *s)
{
    ast_t *tmp;

    if (!s)
        return 0;
    rmast(s->left);
    if (s->cmd)
        rmcmd(s->cmd);
    tmp = s->right;
    free(s);
    rmast(tmp);
    return tmp;
}
