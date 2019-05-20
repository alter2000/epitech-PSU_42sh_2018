/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** something small
*/

#include "shell.h"

static bool is_path(char const *p)
{
    for (; p && *p; p++)
        if (*p == '/')
            return true;
    return false;
}

static char *fpath(char const *p, dict_t *env)
{
    char **path = str_to_tab(dict_get(env, "PATH"), ":");
    char *tmppath = 0;

    for (size_t i = 0; path && path[i]; i++) {
        tmppath = my_strcat(my_strcat(my_strcat(gib(sizeof(*tmppath) * \
            (my_strlen(path[i]) + my_strlen(p) + 2)), path[i]), "/"), p);
        if (!access(tmppath, X_OK))
            break;
        free(tmppath);
    }
    free_array(path);
    return tmppath;
}

char *get_path(char *p, dict_t *env)
{
    char *base;

    if (is_path(p)) {
        if (*p != '/') {
            base = dict_get(env, "PWD");
            return my_strcat(my_strcat(my_strcat(gib(sizeof(char) * \
                    (my_strlen(base) + my_strlen(p) + 2)), base), "/"), p);
        } else
            return p;
    } else
        return fpath(p, env);
}
