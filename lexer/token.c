/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** something small
*/

#include "shell.h"

char const *scan_toklist(char *name, char const * const *toklist)
{
    return 0;
}

bool split_tok(ast_t *ast, char const *tok, char const * const *toklist)
{
    return 0;
}

bool token(ast_t *ast, char const * const *toklist)
{
    const char *tok = 0;

    if (ast->left)
        token(ast->left, toklist);
    if (ast->right)
        token(ast->right, toklist);
    if (ast->type == T_EXPR) {
        tok = scan_toklist(ast->name, toklist);
        if (tok)
            return split_tok(ast, tok, toklist);
    }
    return (tok);
}
