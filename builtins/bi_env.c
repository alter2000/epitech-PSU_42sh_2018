/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** something small
*/

#include "shell.h"

int cmd_setenv(int ac, char **av, sh_t *sh)
{
    if (ac == 1) {
        for (dict_t *d = sh->env; d; d = d->next)
            my_printf("%s=%r\n", d->k, d->v);
        return sh_setexc(sh, 0);
    } else if (ac == 2 || ac == 3) {
        if (!setenv_is_sane(av[1]))
            return sh_setexc(sh, 1);
        dict_push(sh->env, my_strdup(av[1]), my_strdup(ac == 2 ? "" : av[2]));
        return sh_setexc(sh, 0);
    } else {
        my_fputs("setenv: Too many arguments.", STDERR_FILENO);
        return sh_setexc(sh, 1);
    }
}

int cmd_unsetenv(int ac, char **av, sh_t *sh)
{
    if (ac == 1) {
        my_fputs("unsetenv: Too few arguments.", STDERR_FILENO);
        return sh_setexc(sh, 1);
    }
    for (int i = 1; i < ac; i++)
        dict_pop(&sh->env, av[i]);
    return sh_setexc(sh, 0);
}

int cmd_env(int ac, char **av, sh_t *sh)
{
    for (dict_t *d = sh->env; d; d = d->next)
        my_printf("%s=%s\n", d->k, d->v);
    return sh_setexc(sh, 0);
}
