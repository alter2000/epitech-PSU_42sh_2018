/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** something small
*/

#include "shell.h"

dict_t *mkdict(char **env)
{
    dict_t *dict;

    if (!env || !*env)
        return 0;
    dict = gib(sizeof(*dict));
    dict->k = env_get_key(*env);
    dict->v = env_get_val(*env);
    dict->next = mkdict(env + 1);
    return dict;
}

void rmdict(dict_t *dict)
{
    dict_t *tmp;

    if (!dict)
        return;
    free(dict->k);
    free(dict->v);
    tmp = dict->next;
    free(dict);
    rmdict(tmp);
}

char *dict_get(dict_t *d, char const *k)
{
    for (; d; d = d->next)
        if (!my_strcmp(d->k, k))
            return d->v;
    return 0;
}

char  *dict_pop(dict_t **d, char const *key)
{
    char *val = 0;

    for (dict_t *cur = *d, *prev = 0; cur; prev = cur, cur = cur->next)
        if (!my_strcmp(cur->k, key)) {
            if (!prev)
                *d = cur->next;
            else
                prev->next = cur->next;
            val = cur->v;
            free(cur);
            return val;
        }
    return val;
}

dict_t *dict_push(dict_t *d, char *key, char *val)
{
    dict_t *tmp = d;

    if (!tmp)
        return 0;
    for (; tmp->next; tmp = tmp->next)
        if (!my_strcmp(tmp->next->k, key)) {
            free(tmp->next->v);
            tmp->next->v = val;
            return tmp->next;
        }
    tmp->next = gib(sizeof(*tmp));
    tmp->next->k = key;
    tmp->next->v = val;
    return tmp->next;
}
