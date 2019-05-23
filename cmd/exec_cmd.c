/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** something small
*/

#include <string.h>
#include "shell.h"

static void handle_sigs(int s, sh_t *sh)
{
    if (WIFSIGNALED(s) && WTERMSIG(s) != SIGFPE) {
        my_fputstr(strsignal(WTERMSIG(s)), STDERR_FILENO);
    } else if (WIFSIGNALED(s) && WTERMSIG(s) == SIGFPE)
        my_fputstr("Floating exception", STDERR_FILENO);
    if (WCOREDUMP(s))
        my_fputstr(" (core dumped)", STDERR_FILENO);
    my_fputs("", STDERR_FILENO);
    sh_setexc(sh, WTERMSIG(s));
}

static void forky_exec(char *fp, cmd_t *cmd)
{
    int s = 0;
    pid_t pid = fork();

    if (pid > 0) {
        wait(&s);
    } else if (!pid) {
        execve(fp, cmd->av, env_to_tab(cmd->sh->env));
        perror(fp);
        exit(84);
    } else {
        perror(fp);
        return;
    }
    if (WIFEXITED(s)) {
        sh_setexc(cmd->sh, WEXITSTATUS(s));
    } else
        handle_sigs(s, cmd->sh);
}

int cmd_exec(cmd_t *cmd)
{
    char *fullpath = get_path(cmd->av[0], cmd->sh->env);

    if (fullpath && *fullpath == '/') {
        forky_exec(fullpath, cmd);
        free(fullpath);
        return 0;
    } else {
        return my_fputstr(cmd->av[0], STDERR_FILENO) + \
            my_fputs(": Command not found.", STDERR_FILENO);
    }
}
