/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** something small
*/

#include "shell.h"

int cmd_exit(int ac, char **av, sh_t *sh)
{
    if (isatty(STDOUT_FILENO))
        my_puts("exit");
    sh->eof = true;
    if (ac == 1)
        exit(sh->exc);
    else if (ac == 2)
        exit(my_atoll((const char *)av[1]));
    else {
        my_fputs("exit: Expression Syntax.", STDERR_FILENO);
        return sh_setexc(sh, 1);
    }
}

int cmd_jobs(int ac, char **av, sh_t *sh)
{
    return 0;
}
