/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** something small
*/

#include "my.h"

int my_vfputstr(int const fd, size_t const strs, ...)
{
    va_list ap;

    va_start(ap, strs);
    for (size_t i = 0; i < strs; i++) {
        my_fputstr(va_arg(ap, char *), STDOUT_FILENO);
    }
    va_end(ap);
    return strs;
}
