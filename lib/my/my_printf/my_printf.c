/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_printf main file
*/

#include "../my.h"
#include "my_printf.h"

int my_printf(char const *fmt, ...)
{
    va_list ap;
    int chars;

    va_start(ap, fmt);
    chars = pstuff(fmt, ap);
    va_end(ap);
    return chars;
}

int pstuff(char const *fmt, va_list ap)
{
    unsigned int ch = 0;

    for (unsigned int flag = 0, chk = 0, prec = 0, width = 0; *fmt; ) {
        if (*fmt != '%') {
            ch += my_putchar(*fmt++);
            continue;
        } else
            fmt++;
        do {
            chk = set_flags(*fmt, &flag);
            fmt += chk;
        } while (chk);
        width = my_isdigit(*fmt) ? my_atoi(&fmt) : 0;
        if (*fmt == '.')
            prec = (my_isdigit(*++fmt)) ? my_atoi(&fmt) : 0;
        ch += put(mkprintf_arg(setlen(&fmt, &flag), *fix_flags(&flag), \
                    width, prec), ap);
    }
    return ch;
}

static unsigned int more_extended_put(char const **fmt, va_list ap)
{
    unsigned int ch = 0;

    switch (**fmt) {
        case 'S': ++(*fmt);
                ch += p_showstr(va_arg(ap, char *));
                break;
        case 'p': ++(*fmt);
                ch += p_showptr(va_arg(ap, size_t));
                break;
        case '%': ++(*fmt);
                ch += my_putchar('%');
                break;
        default: ch += my_putchar('%');
                ch += my_putchar(*(++(*fmt)));
                break;
    }
    return ch;
}

static unsigned int extended_put(printf_arg_t *pa, va_list ap)
{
    unsigned int ch = 0;

    switch (**(pa->fmt)) {
        case 'o': ++(*(pa->fmt));
                ch += p_oct(pa->flags, pa->width, pa->prec, ap);
                break;
        case 'b': ++(*(pa->fmt));
                ch += p_bin(pa->flags, pa->width, pa->prec, ap);
                break;
        case 'c': ++(*(pa->fmt));
                ch += my_putchar((char) va_arg(ap, int));
                break;
        case 's': ++(*(pa->fmt));
                ch += p_putstr(va_arg(ap, char *), pa->flags, pa->width);
                break;
        case 'r': ++(*(pa->fmt));
                ch += p_showraw(va_arg(ap, char *));
                break;
        default: ch += more_extended_put(pa->fmt, ap);
    }
    return ch;
}

unsigned int put(printf_arg_t *pa, va_list ap)
{
    unsigned int ch = 0;

    switch (**(pa->fmt)) {
        case 'd': case 'i': ++(*(pa->fmt));
                ch += p_dec(pa->flags, pa->width, pa->prec, ap);
                break;
        case 'u': ++(*(pa->fmt));
                ch += p_udec(pa->flags, pa->width, pa->prec, ap);
                break;
        case 'x': ++(*(pa->fmt));
                ch += p_hex(pa->flags, pa->width, pa->prec, ap);
                break;
        case 'X': ++(*(pa->fmt));
                ch += p_chex(pa->flags, pa->width, pa->prec, ap);
                break;
        default: ch += extended_put(pa, ap);
    }
    free(pa);
    return ch;
}
