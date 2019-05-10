/*
** EPITECH PROJECT, 2018
** muhlib
** File description:
** memset(3) clone
*/

#include "my.h"

void *my_memset(char *s, char ch, size_t n)
{
    if (!s)
        return 0;
    for (size_t i = 0; i < n; i++)
        s[i] = ch;
    return s;
}

void *gib(size_t n)
{
    void *p = malloc(n);

    while (!p)
        p = malloc(n);
    return my_memset(p, 0, n);
}

void *my_memcpy(void *dest, const void *src, size_t n)
{
    char *t1 = (char *)dest;
    char *t2 = (char *)src;

    if (!t2 || n < 1)
        return 0;
    for (size_t i = 0; i < n; i++)
        t1[i] = t2[i];
    return dest;
}

void *my_memmove(void *dest, const void *src, size_t n)
{
    unsigned char tmp[n];
    my_memcpy(tmp, src, n);
    my_memcpy(dest, tmp, n);
    return dest;
}
