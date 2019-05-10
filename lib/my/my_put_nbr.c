/*
** EPITECH PROJECT, 2018
** muhlib
** File description:
** print number on stdout + get llong
*/

#include "my.h"

size_t my_putnbr_base(int nb, char const *base)
{
    int b = my_strlen(base);

    if (nb < INT_MIN || nb > INT_MAX) {
        write(2, "put_nbr: out of bounds\n", 23);
        return 0;
    }
    if (nb < 0) {
        my_putchar('-');
        my_putnbr_base(-nb, base);
    } else if (nb > b - 1) {
        my_putnbr_base(nb / b, base);
        my_putnbr_base(nb % b, base);
    } else
        my_putchar(base[nb]);
    return nb;
}

size_t my_putnbr(int nb)
{
    return my_putnbr_base(nb, "0123456789");
}

char *my_itoa(int nb)
{
    short sign = (nb < 0);
    char *str = gib(my_numlen(nb) + sign + 1);
    short left = 0;
    unsigned int i = 0;
    nb = (nb < 0) ? -nb : nb;

    do {
        left = nb % 10;
        nb /= 10;
        str[i++] = left + '0';
    } while (nb > 0);
    if (sign)
        str[i++] = '-';
    str[i] = '\0';
    return my_revstr(str);
}

long double my_strtold(char *s, char **end)
{
    long double nbr = 0;
    bool neg;

    if (!s || !*s)
        return 0;
    for (; *s && my_isspace(*s); s++);
    neg = (*s == '-' && s++);
    for (;*s && my_isdigit(*s); s++)
        nbr = neg ? nbr * 10 - (*s - '0') : nbr * 10 + (*s - '0');
    if (*s == '.' && s++)
        for (long double w = 0.1 ; *s && my_isdigit(*s); w /= 10, s++)
            nbr = neg ? nbr - (*s - '0') * w : nbr + (*s - '0') * w;
    if (*s && end)
        *end = s;
    return nbr;
}

long long int my_strtoll(char *s, char **end)
{
    int nbr = 0;
    bool neg = false;

    if (!s || !*s)
        return 0;
    for (; *s && my_isspace(*s); s++);
    neg = (*s == '-' && s++);
    for (;*s && my_isdigit(*s); s++)
        nbr = neg ? nbr * 10 - (*s - '0') : nbr * 10 + (*s - '0');
    if (*s && end)
        *end = s;
    return nbr;
}
