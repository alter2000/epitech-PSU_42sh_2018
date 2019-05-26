/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** something small
*/

#include "shell.h"

static const char * const builtin_aliases[] = {
    "ls='ls --color=auto'",
0};

static void sighandle(int sig)
{
    int st = 0;

    if (sig != SIGINT && sig != SIGSTOP && sig != SIGQUIT)
        return;
    my_puts("");
    if (waitpid(-1, &st, WNOHANG) == -1 && isatty(STDOUT_FILENO))
        my_putstr(SHELL_PS1);
}

static void sig_init(void)
{
    signal(SIGINT, sighandle);
    signal(SIGSTOP, sighandle);
    signal(SIGQUIT, sighandle);
}

int main(int ac, char **av, char **env)
{
    sh_t sh = {mkdict(env), NULL, mkdict((char **)builtin_aliases), \
        stdin, stdout, stderr, 0, false, SH_SHOWTREE};

    sig_init();
    if (ac > 1)
        return noninteractive(ac, av, &sh);
    return loop(&sh);
}
