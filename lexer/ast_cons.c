/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** something small
*/

#include "shell.h"

static char *uncomment(char *s)
{
    int cchar = is_in('#', s);

    if (cchar == -1)
        return s;
    else
        s[cchar] = 0;
    return s;
}

static bool sane_quotes(char *s , char qchar, int counting)
{
    size_t total = 0;

    for (size_t i = 0; s[i]; i++)
        total += (s[i] == qchar && i > 0 && s[i - 1] != '\\');
    if (total % 2)
        fprintf(stderr, "Unmatched '%c'\n", qchar);
    return !(total % 2);
}

static bool sane_input(char *s)
{
    return sane_quotes(s, '\'', 2) && sane_quotes(s, '"', 2);
}

ast_t *mkast(char *s, sh_t *sh)
{
    ast_t *ast;

    if (!sane_input(s))
        return 0;
    ast = gib(sizeof(*ast));
    ast->cmd = mkcmd(sh, str_to_tab(uncomment(s), " \t\n"));
    ast->type = T_EXEC;
    return ast;
}

void rmast(ast_t *s)
{
    ast_t *tmp;

    if (!s)
        return;
    rmast(s->left);

    free(s->name);
    if (s->cmd)
        rmcmd(s->cmd);

    tmp = s->right;
    free(s);
    rmast(tmp);
}
