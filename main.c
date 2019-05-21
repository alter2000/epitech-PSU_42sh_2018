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

static const char *builtin_aliases[] = {
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

static int noninteractive(int ac, char **av, sh_t *sh)
{
    ast_t *p;

    for (int i = 2; i < ac; i++) {
        p = parse(mkast(av[i], sh));
        show_tab((char const **)p, "");
    }
    return sh->exc;
}

static int loop(int ac, char **av, sh_t *sh)
{
    ast_t *curast;

    sig_init();
    if (ac > 1 && !my_strcmp(av[1], "-c"))
        return noninteractive(ac, av, sh);
    if (!dict_get(sh->env, "PATH"))
        cmd_setenv(3, DEFAULT_PATH, sh);
    while (!sh->eof) {
        curast = prompt(sh);
        parse(curast);
        rmast(curast);
    }
    return sh->exc;
}

int main(int ac, char **av, char **env)
{
    sh_t sh = {mkdict(env), NULL, mkdict((char **)builtin_aliases), \
        {0, 0, {0, O_RDONLY}, {1, O_WRONLY}, {2, O_WRONLY}}, \
        0, false};
    int ret = loop(ac, av, &sh);

    rmdict(sh.env);
    return ret;
}
