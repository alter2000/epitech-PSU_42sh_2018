/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** something small
*/

#include "my.h"

node_t *list_pop_head(list_t *list)
{
    return list_cut_node(list, list->head);
}

node_t *list_pop_tail(list_t *list)
{
    return list_cut_node(list, list->tail);
}

void *list_pop_a_head(list_t *list)
{
    return list_a_cut_node(list, list->head);
}

void *list_pop_a_tail(list_t *list)
{
    return list_a_cut_node(list, list->tail);
}
