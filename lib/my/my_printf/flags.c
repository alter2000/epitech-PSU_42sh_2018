/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** flag consumption funcs
*/

#include "../my.h"
#include "my_printf.h"
#include <stdint.h>

int set_flags(char const ch, unsigned int *flags)
{
    switch (ch) {
        case '#': *flags |= F_HASH;
                return 1;
        case '0': *flags |= F_ZERO;
                return 1;
        case '-': *flags |= F_LEFT;
                return 1;
        case ' ': *flags |= F_SPACE;
                return 1;
        case '+': *flags |= F_PLUS;
                return 1;
        default: return 0;
    }
}

void check_ptr(char const **fmt, unsigned int *flags)
{
    switch (**fmt) {
        case 'j' :
            *flags |= (sizeof(intmax_t) == sizeof(long)) ? F_LONG : F_LLONG;
            (*fmt)++;
            break;
        case 'z' :
            *flags |= (sizeof(size_t) == sizeof(long)) ? F_LONG : F_LLONG;
            (*fmt)++;
            break;
        case 't' :
            *flags |= (sizeof(ptrdiff_t) == sizeof(long)) ? F_LONG : F_LLONG;
            (*fmt)++;
            break;
        default:
            break;
    }
}

char const **setlen(char const **fmt, unsigned int *flags)
{
    switch (**fmt) {
        case 'h' : *flags |= F_SHORT;
                if (*(++(*fmt)) == 'h') {
                    *flags |= F_CHAR;
                    (*fmt)++;
                }
                break;
        case 'l' : *flags |= F_LONG;
                if (*(++(*fmt)) == 'l') {
                    *flags |= F_LLONG;
                    (*fmt)++;
                }
                break;
        default: check_ptr(fmt, flags);
                break;
    }
    return fmt;
}

unsigned int *fix_flags(unsigned int *flags)
{
    if (*flags & F_LEFT && *flags & F_ZERO)
        *flags &= ~F_ZERO;
    if (*flags & F_SPACE && *flags & F_PLUS)
        *flags &= ~F_SPACE;
    return flags;
}
