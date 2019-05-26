/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** something small
*/

#include "shell.h"

char *next_tok(char **str, char const *tok)
{
    char *cur = my_strstr(*str, tok);
    char *ret = *str;

    *str = (cur) ? cur : *str + my_strlen(*str);
    return ret;
}
