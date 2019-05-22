/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** something small
*/

#include "shell.h"

char *uncomment(char *s)
{
    int cchar = is_in('#', s);

    if (cchar == -1)
        return s;
    else
        s[cchar] = 0;
    return s;
}

ast_t *mkast(char *s, sh_t *sh)
{
    ast_t *ast = gib(sizeof(*ast));

    ast->cmd = mkcmd(sh, str_to_tab(uncomment(s), " \t\n"));
    return ast;
}

void rmast(ast_t *s)
{
    (void)s;
}
