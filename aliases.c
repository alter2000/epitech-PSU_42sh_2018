/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** something small
*/

#include "shell.h"

int cmd_alias(int ac, char **av, sh_t *sh)
{
    switch (ac) {
        case 1: for (dict_t *d = sh->alias; d; d = d->next)
                    my_printf("%s\t%s\n", d->k, d->v);
            return sh_setexc(sh, 0);
        case 2: for (dict_t *d = sh->alias; d && d->k && *(d->k); d = d->next)
                    if (!my_strcmp(av[1], d->k))
                        my_printf("%s\t%s\n", d->k, d->v);
            return sh_setexc(sh, 0);
        case 3: dict_push(sh->alias, my_strdup(av[1]), my_strdup(av[2]));
            return sh_setexc(sh, 0);
        default: dict_push(sh->alias, my_strdup(av[1]), \
                         tab_to_str(&av[2], " ", "(", ")"));
            return sh_setexc(sh, 0);
    }
}

int cmd_unalias(int ac, char **av, sh_t *sh)
{
    if (sh->alias)
        for (int i = 1; i < ac; i++)
            dict_pop(&sh->alias, av[i]);
    return sh_setexc(sh, 0);
}
