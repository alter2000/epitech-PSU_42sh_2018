/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** something small
*/

#include "shell.h"

ast_t *mkast(char *s, sh_t *sh)
{
    ast_t *ast = gib(sizeof(*ast));

    ast->cmd = mkcmd(sh, str_to_tab(s, " \t\n"));
    return ast;
}

void rmast(ast_t *s)
{
    (void)s;
}
