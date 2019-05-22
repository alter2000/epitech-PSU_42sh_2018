/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** something small
*/

#include "shell.h"

const redir_t redirs[] = {
    {"<", O_RDONLY, {-1, -1}, {-1, -1}, {-1, -1}},
    {">", O_WRONLY | O_CREAT | O_TRUNC, {-1, -1}, {-1, -1}, {-1, -1}},
    {">>", O_WRONLY | O_CREAT | O_APPEND, {-1, -1}, {-1, -1}, {-1, -1}},
    {"2>", O_WRONLY | O_CREAT | O_TRUNC, {-1, -1}, {-1, -1}, {-1, -1}},
    {"2>>", O_WRONLY | O_CREAT | O_APPEND, {-1, -1}, {-1, -1}, {-1, -1}},
    {0, 0, {-1, -1}, {-1, -1}, {-1, -1}},
};

static const char * const builtin_aliases[] = {
    "ls='ls --color=auto'",
0};

static void sighandle(int sig)
{
    if (sig != SIGINT && sig != SIGSTOP && sig != SIGQUIT)
        return;
    if (isatty(STDOUT_FILENO))
        my_printf("\n%s", SHELL_PS1);
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
        {0, 0, {0, O_RDONLY}, {1, O_WRONLY}, {2, O_WRONLY}}, \
        STDIN_FILENO, 0, false};
    int ret;

    sig_init();
    if (ac > 1)
        return noninteractive(ac, av, &sh);
    ret  = loop(&sh);
    rmdict(sh.env);
    return ret;
}
