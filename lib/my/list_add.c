/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** something small
*/

#include "my.h"

list_t *list_append(list_t *ls, list_t *p)
{
    if (!ls || !p)
        return 0;
    p->head->p = ls->tail;
    p->head = ls->tail->n;
    return ls;
}

list_t *list_prepend(list_t *ls, list_t *p)
{
    if (!ls || !p)
        return 0;
    ls->head->p = p->tail;
    p->tail->n = ls->head;
    return ls;
}

list_t *list_n_append(list_t *list, node_t *node)
{
    if (!list)
        return list_create(node);
    node->p = list->tail;
    if (list->tail)
        list->tail->n = node;
    else
        list->head = node;
    list->tail = node;
    return list;
}

list_t *list_n_prepend(list_t *list, node_t *node)
{
    if (!list)
        return list_create(node);
    node->n = list->head;
    if (list->head)
        list->head->p = node;
    else
        list->tail = node;
    list->head = node;
    return list;
}
