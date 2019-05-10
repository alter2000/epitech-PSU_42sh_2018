/*
** EPITECH PROJECT, 2018
** muhlib
** File description:
** find if string contains only alphanumerics
*/

#include "my.h"

int my_str_isalpha(char const *str)
{
    for (int i = 0; str && str[i]; i++)
        if (!(my_isupper(str[i]) || my_islower(str[i])))
            return 0;
    return 1;
}

int my_str_islower(char const *str)
{
    for (int i = 0; str && str[i]; i++)
        if (!my_islower(str[i]))
            return 0;
    return 1;
}

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (!my_isupper(str[i]))
            return 0;
    return 1;
}

int my_str_isnum(const char *str)
{
    for (int i = 0; str && str[i]; i++)
        if (!my_isdigit(str[i]))
            return 0;
    return 1;
}

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (!my_isprintable(str[i]))
            return 0;
    return 1;
}
