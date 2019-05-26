/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** something small
*/

#include <string.h>
#include "shell.h"

static char const *scan_toklist(char *name, char const * const *toklist)
{
    char quote = 0;

    for (size_t i = 0; name[i]; i++) {
        if (is_in(name[i], "\"'") != -1 && !esc(name, i)) {
            quote = name[i];
            do {
                ++i;
            } while (name[i] && (name[i] != quote || esc(name, i)));
        }
        for (size_t j = 0; toklist[j]; j++)
            if (!strncmp(name + i, toklist[j], my_strlen(toklist[j])) \
                    && !esc(name, i))
                return toklist[j];
    }
    return 0;
}

static token_t get_type(char *tstr)
{
    for (size_t i = 0; MYSHTOK_LIST[i]; i++)
        if (!strncmp(tstr, MYSHTOK_LIST[i], my_strlen(MYSHTOK_LIST[i])))
            return i;
    return T_EXPR;
}

bool split_tok(ast_t *ast, char const *tok, char const * const *toklist)
{
    char *tmp = ast->name;

    ast->left = mknode();
    ast->right = mknode();
    ast->left->name = next_tok(&tmp, tok);
    ast->type = get_type(tmp);
    tmp[0] = '\0';
    if (ast->type != T_EXPR)
        tmp += my_strlen(MYSHTOK_LIST[ast->type]);
    ast->right->name = tmp;
    tok = scan_toklist(ast->right->name, toklist);
    if (tok)
        return split_tok(ast->right, tok, toklist);
    return true;
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
    return true;
}
