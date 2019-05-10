/*
** EPITECH PROJECT, 2018
** CPool_Day07_2018
** File description:
** find if char is letter
*/

#include "my.h"

int my_isalpha(char const ch)
{
    return (my_isupper(ch) || my_islower(ch));
}

int my_isprintable(char const ch)
{
    return ((ch >= 32 && ch <= 126) || my_isspace(ch));
}

int my_isdigit(char const ch)
{
    return (ch >= '0' && ch <= '9');
}

int my_islower(char const ch)
{
    return (ch >= 'a' && ch <= 'z');
}

int my_isupper(char const ch)
{
    return (ch >= 'A' && ch <= 'Z');
}
