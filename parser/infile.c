/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** something small
*/

#include "shell.h"

void infile(char *sp, sh_t *sh)
{
    int fd = open(sp, O_RDONLY);

    if (fd < 0) {
        my_vfputstr(STDERR_FILENO, 3, "42sh: ", sp, ": No such file or "
                "directory\n");
        exit(1);
    }
    loop(sh);
}
