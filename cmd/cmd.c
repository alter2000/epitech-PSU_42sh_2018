/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** something small
*/

#include "shell.h"

void rmcmd(cmd_t *c)
{
    if (c->av)
        free_array(c->av);
    free(c->name);
    free(c);
}

cmd_t *mkcmd(sh_t *sh, char **c)
{
    cmd_t *cmd = gib(sizeof(*cmd));

    cmd->av = c;
    cmd->ac = my_tablen(cmd->av);
    cmd->sh = sh;
    cmd->name = my_strdup(cmd->av ? *cmd->av : "NONECMD");
    return cmd;
}

bool cmd_builtins(cmd_t *cmd, cmd_t const *bi)
{
    int i = 0;

    for (; bi[i].name && cmd->ac; i++)
        if (!my_strcmp(bi[i].name, cmd->name)) {
            bi[i].func(cmd->ac, cmd->av, cmd->sh);
            return true;
        }
    return false;
}
