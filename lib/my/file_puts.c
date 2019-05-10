/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** something small
*/

#include "my.h"

size_t my_fputstr(char *s, int const fd)
{
    return write(fd, s, my_strlen(s));
}

size_t my_fputs(char *s, int const fd)
{
    return write(fd, s, my_strlen(s)) + write(fd, "\n", 1);
}

int my_fputchar(char const c, int const fd)
{
    return write(fd, &c, 1);
}
