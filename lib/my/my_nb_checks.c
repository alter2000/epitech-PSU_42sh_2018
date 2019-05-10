/*
** EPITECH PROJECT, 2018
** muhlib
** File description:
** number calc
*/

#include "my.h"

int my_is_prime(int const nb)
{
    int prime = 1;

    if (nb <= 1)
        return 0;
    for (int i = 2; i <= (nb / 2); i++) {
        if (nb % i == 0) {
            prime = 0;
            break;
        }
    }
    return prime;
}

size_t my_numlen(long long int n)
{
    int len = 0;

    if (!n)
        return 1;
    if (n < 0)
        len++;
    for (; n; n /= 10, len++);
    return len;
}
