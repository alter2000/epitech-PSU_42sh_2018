/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** something small
*/

#include "my.h"

char my_tolower(const char c)
{
    return (my_islower(c)) ? c : c + ('a' - 'A');
}

char my_toupper(const char c)
{
    return (my_isupper(c)) ? c : c - ('a' - 'A');
}
