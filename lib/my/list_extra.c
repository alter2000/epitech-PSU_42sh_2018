/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** something small
*/

#include "my.h"

void list_rm(list_t *ls)
{
    node_t *n = (ls) ? ls->head : 0;

    if (!ls)
        return;
    for (node_t *tmp = n->n; n; n = tmp)
        node_rm(n);
    free(ls);
}

list_t *list_a_append(list_t *list, void *p)
{
    return list_n_prepend(list, node_create(p));
}

list_t *list_a_prepend(list_t *list, void *p)
{
    return list_n_append(list, node_create(p));
}
