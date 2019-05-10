/*
** EPITECH PROJECT, 2018
** muhlib
** File description:
** change string to word array
*/

#include <stdlib.h>
#include "my.h"

static size_t count_words(char const *str, char const *cmp)
{
    size_t words = 0;

    for (size_t i = 0; str && str[i]; i++)
        words += !!(is_in(str[i], cmp) != -1);
    return words;
}

char **str_to_tab(char * const str, char const *cmp)
{
    char **arr = 0;
    size_t i = 0;

    if (!str || !*str)
        return 0;
    arr = gib(sizeof(*arr) * (count_words(str, cmp) + 2));
    for (char *sc = (char *)str; *sc; i++)
        arr[i] = my_strsep(&sc, cmp);
    return arr;
}

char *tab_to_str(char ** const tab, char const *sep, \
                char const *begin, char const *end)
{
    char *str = my_strdup(begin);

    if (!tab || !*tab)
        return 0;
    if (!sep)
        sep = " ";
    str = my_strcat(regib(str, my_strlen(*tab)), *tab);
    for (size_t i = 1; tab[i]; i++)
        str = my_strcat(my_strcat(regib(str, \
                my_strlen(tab[i]) + my_strlen(sep)), sep), tab[i]);
    str = my_strcat(regib(str, my_strlen(end)), end);
    return str;
}

int show_tab(char const **tab, char const *sep)
{
    int res = 0;

    if (!sep)
        sep = "\n";
    for (uint_t i = 0; tab && tab[i]; i++) {
        res += my_putstr(tab[i]);
        res += my_putstr(sep);
    }
    return res;
}

void free_array(char **m)
{
    size_t i = 0;

    if (!m)
        return;
    if (*m) {
        for (; m[i]; i++)
            free(m[i]);
        free(m[i]);
    }
    free(m);
}
