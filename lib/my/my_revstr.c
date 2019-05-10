/*
** EPITECH PROJECT, 2018
** muhlib
** File description:
** reverse() implementation
*/

#include "my.h"

char *my_revstr(char *str)
{
    int a = 0;
    int b = my_strlen(str) - 1;

    if (!str)
        return 0;
    while (a < b)
        my_swap((int *) &str[a], (int *) &str[b]);
    return str;
}

void my_swap(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;
}

void bsort_int(int *array, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size - 1; j++)
            if (array[j] > array[j + 1])
                my_swap(&array[j], &array[j + 1]);
}
