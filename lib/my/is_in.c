/*
** EPITECH PROJECT, 2018
** CPool_bistro-matic_2018
** File description:
** like Python `in' operator
*/

#include "my.h"

int is_in(char const elem, char const *set)
{
    for (size_t i = 0; set && set[i]; i++)
        if (set[i] == elem)
            return i;
    return -1;
}

size_t my_strpn(char const *str, char const *check, bool cspn)
{
    char const *sc = str;

    for (; sc && *sc; sc++)
        if ((cspn && is_in(*sc, check) != -1) \
        || (!cspn && is_in(*sc, check) == -1))
            break;
    return sc - str;
}

int my_memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *p1 = s1;
    const unsigned char *p2 = s2;

    if (!p1 || !p2)
        return 0;
    while (n--)
        if (*p1 == *p2) {
            p1++;
            p2++;
        } else
            return *p1 - *p2;
    return 0;
}

char *my_strstr(char *str, const char *to_find)
{
    size_t n = my_strlen(to_find);

    while(*str)
        if(!my_memcmp(str++, to_find, n))
            return str - 1;
    return 0;
}

int my_isspace(char const ch)
{
    return (ch == ' ' || ch == '\t' || ch == '\v' \
            || ch == '\r' || ch == '\n');
}
