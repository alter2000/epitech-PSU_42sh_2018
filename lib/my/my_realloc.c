/*
** EPITECH PROJECT, 2018
** CPool_Day07_2018
** File description:
** reallocate memory
*/

#include "my.h"

char *my_realloc(char *s, int extra)
{
    char *newstr = 0;
    int oldsize = my_strlen(s);
    int newsize = 1 + oldsize + extra;

    newstr = my_strncpy(gib(sizeof(char) * (newsize + 2)), s, oldsize);
    free(s);
    return newstr;
}

void *regib(char *s, int extra)
{
    return (void *)my_realloc(s, extra);
}

size_t my_tablen(char const **t)
{
    size_t i;

    for (i = 0; t && t[i] && *t[i]; i++);
    return i;
}
