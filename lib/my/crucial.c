/*
** EPITECH PROJECT, 2018
** CPool_Day04_2018
** File description:
** essential functions
*/

#include "my.h"

size_t my_strlen(char const *str)
{
    size_t i;

    for (i = 0; str && str[i]; i++);
    return i;
}

int my_putchar(int const c)
{
    return c > 0 ? write(STDOUT_FILENO, &c, 1) : 0;
}

size_t my_putstr(char const *str)
{
    return str ? write(STDOUT_FILENO, str, my_strlen(str)) : 0;
}

char *my_strdup(char const *src)
{
    return src ? my_strcpy(gib((my_strlen(src) + 1) * sizeof(char)), src) : 0;
}
