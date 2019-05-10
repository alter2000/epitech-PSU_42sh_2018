/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** something small
*/

#include "my.h"

char *my_strtok(char *p, char const *cmp)
{
    static char *pc = 0;

    if (p)
        pc = p;
    else if (!pc)
        return 0;
    p = pc + my_strpn(pc, cmp, false);
    pc = p + my_strpn(p, cmp, true);
    if (pc == p)
        return pc = 0;
    pc = *pc ? *pc = 0, pc + 1 : 0;
    return p;
}

char *my_strsep(char ** const p, char const *cmp)
{
    size_t n = 0;
    char *ret = 0;

    if (!p || !*p || !**p)
        return 0;
    for (; **p && is_in(**p, cmp) != -1; (*p)++);
    for (; (*p)[n] && is_in((*p)[n], cmp) == -1; n++);
    ret = my_strndup(*p, n);
    *p += n;
    return ret;
}
