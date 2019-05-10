/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** modified functions for printf
*/

#include "../my.h"
#include "my_printf.h"

unsigned int p_bin(unsigned int flags, unsigned int width, \
        unsigned int precision, va_list arg)
{
    flags &= ~F_HASH;
    if (flags & F_LLONG)
        return p_putnbr(va_arg(arg, long long), "01", width);
    if (flags & F_LONG)
        return p_putnbr(va_arg(arg, long), "01", width);
    if (flags & F_CHAR)
        return p_putnbr((char) va_arg(arg, int), "01", width);
    if (flags & F_SHORT)
        return p_putnbr((short int) va_arg(arg, int), "01", width);
    return p_putnbr(va_arg(arg, int), "01", width);
}

unsigned int p_showraw(char const *str)
{
    unsigned int c = 0;

    for (unsigned int i = 0; str && str[i]; i++) {
        if (my_isprintable(str[i]))
            c += my_putchar(str[i]);
        if (str[i] == 27)
            c += my_putstr("^[");
        if (str[i] != 27 && !my_isprintable(str[i])){
            c += my_putchar('\\');
            if (str[i] < 16)
                c += my_putchar('0');
            c += my_putnbr_base(str[i], "01234567");
        }
    }
    return c;
}
