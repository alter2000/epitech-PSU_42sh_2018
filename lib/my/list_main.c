/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** something small
*/

#include "my.h"

list_t *list_create(node_t *n)
{
    list_t *list = gib(sizeof(*list));

    list->head = n;
    list->tail = n;
    return list;
}

node_t *node_create(void *p)
{
    node_t *node = gib(sizeof(*node));

    node->d = p;
    return node;
}

void node_rm(node_t *node)
{
    if (node->d)
        free(node->d);
    free(node);
}

node_t *list_cut_node(list_t *ls, node_t *node)
{
    if (!ls || !node)
        return 0;
    if (node == ls->head)
        ls->head = node->n;
    if (node == ls->tail)
        ls->tail = node->p;
    if (node->n)
        node->n->p = node->p;
    if (node->p)
        node->p->n = node->n;
    return node;
}

void *list_a_cut_node(list_t *ls, node_t *node)
{
    node_t *n = list_cut_node(ls, node);
    void *p = n->d;

    free(n);
    return p;
}
