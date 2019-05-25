/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** something small
*/

#include "shell.h"

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
    if (ac >= 2 && !my_strcmp(av[1], "-c")) {
        if (ac == 2)
            return sh->exc;
        rmast(parse(mkast(av[2], sh)));
    } else
        infile(av[1], sh);
    rmsh(sh);
    return sh->exc;
}

int loop(sh_t *sh)
{
    ast_t *curast;

    if (!dict_get(sh->env, "PATH"))
        cmd_setenv(3, DEFAULT_PATH, sh);
    while (!sh->eof) {
        curast = prompt(sh);
        parse(curast);
        rmast(curast);
    }
    rmsh(sh);
    return sh->exc;
}
