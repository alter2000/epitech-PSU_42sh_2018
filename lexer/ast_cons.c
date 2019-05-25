/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** something small
*/

#include "shell.h"

static char *uncomment(char *s)
{
    enum cmd_state state = STATE_GENERAL;

    for (size_t i = 0; s && s[i]; i++) {
        if (s[i] == '\'' && !esc(s, i))
            state = (state == STATE_QUOTE) ? STATE_GENERAL : STATE_QUOTE;
        if (s[i] == '"' && !esc(s, i))
            state = (state == STATE_DQUOTE) ? STATE_GENERAL : STATE_DQUOTE;
        if (s[i] == '#' && !esc(s, i) && state == STATE_GENERAL)
            s[i] = 0;
    }
    return s;
}

static bool sane_quotes(char *s , char qchar)
{
    size_t total = 0;

    for (size_t i = 0; s[i]; i++)
        total += (s[i] == qchar && !esc(s, i));
    if (total % 2)
        fprintf(stderr, "Unmatched '%c'\n", qchar);
    return !(total % 2);
}

static bool sane_input(char *s)
{
    s = uncomment(s);
    return sane_quotes(s, '\'') && sane_quotes(s, '"');
}

ast_t *mknode(void)
{
    ast_t *n = gib(sizeof(*n));

    n->name = "NONAME";
    n->type = T_EXPR;
    return n;
}

ast_t *mkast(char *s, sh_t *sh)
{
    ast_t *ast;

    if (!sane_input(s))
        return 0;
    ast = mknode();
    ast->name = s;
    ast->cmd = mkcmd(sh, str_to_tab(s, " \t\n"));
    /* for (size_t i = 0; EXPR_TOKENS[i]; i++) */
    /*     if (!token(ast, EXPR_TOKENS[i])) */
    /*         return rmast(ast); */
    /* eval_aliases(ast, sh->alias); */
    return ast;
}

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
