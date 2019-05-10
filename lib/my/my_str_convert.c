/*
** EPITECH PROJECT, 2018
** muhlib
** File description:
** string editing
*/

#include "my.h"

char *my_strcapitalize(char *str)
{
    for (int i = 0; i < str[i]; i++)
        if (my_isalpha(str[i]) && my_islower(str[i]) \
                && (i == 0 || my_isspace(str[i - 1])))
            str[i] -= 32;
    return str;
}

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i]; i++)
        str[i] = my_tolower(str[i]);
    return str;
}

char *my_strupcase(char *str)
{
    for (int i = 0; str[i]; i++)
        str[i] = my_toupper(str[i]);
    return str;
}

void my_showstr(char const *str)
{
    for (unsigned int i = 0; str[i]; i++)
        if (my_isprintable(str[i]))
            my_putchar(str[i]);
        else {
            my_putchar('\\');
            if (str[i] < 16)
                my_putchar('0');
            my_putnbr_base(str[i], "0123456789abcdef");
        }
}

size_t my_puts(char const *s)
{
    return my_putstr(s) + write(STDOUT_FILENO, "\n", 1);
}
