/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** something small
*/

#include "shell.h"

static void show_ast(ast_t *ast, sh_t *sh)
{
    if (!ast || !sh->showtree)
        return;
    if (ast->type != T_EXPR) {
        my_printf("type: %s\n", MYSHTOK_LIST[ast->type]);
    } else {
        my_printf("expr: ");
        for (size_t i = 0 ; ast->cmd->av[i] ; ++i)
            my_printf("%s ", ast->cmd->av[i]);
        my_putchar('\n');
    }
    if (ast->left) {
        my_printf("left:\t");
        show_ast(ast->left, sh);
    }
    if (ast->right) {
        my_printf("right:\t");
        show_ast(ast->right, sh);
    }
}

int sh_setexc(sh_t *sh, int c)
{
    sh->exc = c;
    return sh->exc;
}

ast_t *prompt(sh_t *sh)
{
    ast_t *ast;
    char *in;

    if (isatty(fileno(sh->infd)) && isatty(STDOUT_FILENO))
        my_putstr(SHELL_PS1);
    in = gnugetl(sh->infd);
    if (!in) {
        cmd_exit(1, 0, sh);
        return 0;
    }
    if (isatty(fileno(sh->infd)) && isatty(STDOUT_FILENO))
        my_puts("");
    ast = mkast(in, sh);
    free(in);
    return ast;
}

int noninteractive(int ac, char **av, sh_t *sh)
{
    ast_t *ast;

    if (ac >= 2 && !my_strcmp(av[1], "-c")) {
        if (ac == 2)
            return sh->exc;
        ast = mkast(av[2], sh);
        show_ast(ast, sh);
        parse(ast, sh);
        rmast(ast);
    } else
        infile(av[1], sh);
    rmsh(sh);
    return sh->exc;
}

int loop(sh_t *sh)
{
    ast_t *ast;

    if (!dict_get(sh->env, "PATH"))
        cmd_setenv(3, DEFAULT_PATH, sh);
    while (!sh->eof) {
        ast = prompt(sh);
        show_ast(ast, sh);
        parse(ast, sh);
        rmast(ast);
    }
    rmsh(sh);
    return sh->exc;
}
