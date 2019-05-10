/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** something small
*/

#include "my.h"

size_t err(char const *errstr)
{
    if (!errstr || !*errstr) {
        write(2, "err: no error string\n", 21);
        return 0;
    }
    write(2, errstr, my_strlen(errstr));
    return 0;
}

size_t errb(char const *errstr)
{
    if (!errstr || !*errstr) {
        write(2, "errb: no error string\n", 22);
        return 0;
    }
    write(2, errstr, my_strlen(errstr));
    _exit(84);
}

size_t errc(char *buf, char const *errstr)
{
    if (!errstr || !*errstr || !buf || !*buf) {
        write(2, "errc: no error string or invalid buffer\n", 32);
        return 0;
    }
    write(2, errstr, my_strlen(errstr));
    free(buf);
    _exit(84);
}

size_t errm(char **buf, char const *errstr)
{
    uint_t i = 0;

    if (!errstr || !buf || !*errstr || !*buf) {
        write(2, "errm: no error string or invalid buffer\n", 32);
        return 0;
    }
    write(2, errstr, my_strlen(errstr));
    for (; buf[i]; i++) free(buf[i]);
    free(buf[i]);
    free(buf);
    _exit(84);
}
