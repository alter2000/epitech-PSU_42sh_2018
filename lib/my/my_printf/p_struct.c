/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** something small
*/

#include "../my.h"
#include "my_printf.h"

printf_arg_t *mkprintf_arg(char const **fmt, unsigned int flag, \
                unsigned int width, unsigned int prec)
{
    printf_arg_t *pa = 0;

    while (!pa)
        pa = malloc(sizeof(*pa));
    pa->flags = flag;
    pa->fmt = fmt;
    pa->width = width;
    pa->prec = prec;
    return pa;
}
