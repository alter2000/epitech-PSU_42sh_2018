/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** something small
*/

#include "shell.h"

char *env_get_key(char const *s)
{
    int idx = is_in('=', s);

    return idx == -1 ? 0 : my_strncpy(gib(sizeof(char) * (idx + 1)), s, idx);
}

char *env_get_val(char const *s)
{
    int idx = is_in('=', s);

    return idx == -1 ? 0 : my_strcpy(gib(sizeof(char) * \
                (my_strlen(s + idx + 1) + 1)), s + idx + 1);
}

size_t env_len(dict_t *env)
{
    size_t len = 0;

    for (; env; env = env->next)
        len++;
    return len;
}

char **env_to_tab(dict_t *env)
{
    size_t i;
    char **tab = gib(sizeof(*tab) * (env_len(env) + 1));

    for (i = 0; env; env = env->next, i++)
        tab[i] = my_strcat(my_strcat(my_strcat(gib(sizeof(char) * \
                (my_strlen(env->k) + my_strlen(env->v) + 2)), \
                        env->k), "="), env->v);
    tab[i] = 0;
    return tab;
}
