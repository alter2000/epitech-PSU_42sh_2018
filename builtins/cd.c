/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** something small
*/

#include "shell.h"

int change_cwd(sh_t *sh, char *dirto)
{
    char p[PATH_MAX * 2] = {0};

    getcwd(p, sizeof(p));
    if (chdir(dirto) || !p[0]) {
        perror(dirto);
        return sh_setexc(sh, 1);
    }
    dict_push(sh->env, "OLDPWD", my_strdup(p));
    dict_push(sh->env, "PWD", my_strdup(getcwd(p, sizeof(p))));
    return 0;
}

int cmd_cd(int ac, char **av, sh_t *sh)
{
    char up[PATH_MAX * 2] = {0};

    if (ac == 1 || (ac == 2 && !my_strcmp(av[1], "~")))
        return change_cwd(sh, dict_get(sh->env, "HOME"));
    if (ac > 2)
        return !my_fputs("cd: Too many arguments.", STDERR_FILENO);
    if (!my_strcmp(av[1], "-"))
        return change_cwd(sh, dict_get(sh->env, "OLDPWD"));
    if (*av[1] == '~' && av[1][1] && av[1][2])
        return change_cwd(sh, my_strcat(my_strcat(my_strcat(up, \
                        dict_get(sh->env, "HOME")), "/"), av[1] + 2));
    return change_cwd(sh, av[1]);
}
