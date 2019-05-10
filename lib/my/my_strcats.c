/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** something small
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, size_t const n)
{
    size_t i = 0;
    char *len = dest + my_strlen(dest);

    for (; src && src[i] && i < n; i++)
        len[i] = src[i];
    len[i] = 0;
    return dest;
}

char *my_strncpy(char *dest, char const *src, size_t const n)
{
    size_t i = 0;

    if (!src || n < 1)
        return 0;
    for (; src[i] && i < n; i++)
        dest[i] = src[i];
    if (i > n)
        dest[i] = 0;
    return dest;
}

char *my_strccat(char *dest, char const *src, char const c)
{
    size_t i = 0;
    char *len = dest + my_strlen(dest);

    for (; src && src[i] && src[i] != c; i++)
        len[i] = src[i];
    len[i] = 0;
    return dest;
}

char *my_strccpy(char *dest, char const *src, char const c)
{
    size_t i = 0;

    if (!src)
        return 0;
    for (; src[i] && src[i] != c; i++)
        dest[i] = src[i];
    dest[i] = 0;
    return dest;
}
