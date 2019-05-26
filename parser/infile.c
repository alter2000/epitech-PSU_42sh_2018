/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** something small
*/

#include "shell.h"

void infile(char *sp, sh_t *sh)
{
    FILE *fd = fopen(sp, "r");

    if (!fd) {
        my_vfputstr(2, 3, "42sh: ", sp, ": No such file or directory\n");
        rmsh(sh);
        exit(1);
    }
    sh->infd = fd;
    loop(sh);
    rmsh(sh);
    if (fclose(fd)) {
        perror("42sh");
        exit(1);
    }
}
