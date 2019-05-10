/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** something small
*/

#include "shell.h"

bool setenv_is_sane(char const *val)
{
    if (!my_isupper(*val) && !my_islower(*val))
        return !my_fputs("setenv: Variable name must begin with a letter", \
                STDERR_FILENO);
    for (; val && *val; val++)
        if (!(my_isalpha(*val) || my_isdigit(*val) \
                || *val == '.' || *val == '_' || *val == '/'))
            return !my_fputs("setenv: Variable name must contain "
                            "alphanumeric characters", STDERR_FILENO);
    return true;
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

    if (isatty(STDOUT_FILENO))
        my_putstr(SHELL_PS1);
    in = getl(STDIN_FILENO);
    if (!in)
        cmd_exit(1, 0, sh);
    if (isatty(STDOUT_FILENO))
        my_puts("");
    ast = mkast(in, sh);
    free(in);
    return ast;
}
