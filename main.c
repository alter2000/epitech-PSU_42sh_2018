/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** something small
*/

#include "shell.h"

static const cmd_t builtins[] = {
    { "setenv",   cmd_setenv,   0, 0, 0 },
    { "unsetenv", cmd_unsetenv, 0, 0, 0 },
    { "env",      cmd_env,      0, 0, 0 },
    { "cd",       cmd_cd,       0, 0, 0 },
    { "exit",     cmd_exit,     0, 0, 0 },
    { 0, 0, 0, 0, 0 }
};

const redir_t redirs[] = {};

static void sighandle(int sig)
{
    if (sig != SIGINT && sig != SIGSTOP)
        return;
    my_printf("\n%s", SHELL_PS1);
}

static int noninteractive(int ac, char **av, sh_t *sh)
{
    cmd_t *cmd;

    for (int i = 1; i < ac; i++) {
        parse(av[i]);
        char **p = str_to_tab(av[i], " \t\n");
        show_tab((char const **)p, "");
        cmd = mkcmd(sh, p);
        if (!cmd_builtins(cmd, builtins) && cmd->ac)
            cmd_exec(cmd);
        rmcmd(cmd);
    }
    return sh->exc;
}

static int loop(int ac, char **av, sh_t *sh)
{
    cmd_t *curcmd;

    signal(SIGINT, sighandle);
    signal(SIGSTOP, sighandle);
    signal(SIGQUIT, sighandle);
    if (ac > 1)
        noninteractive(ac, av, sh);
    while (!sh->eof) {
        curcmd = prompt(sh);
        if (!cmd_builtins(curcmd, builtins) && curcmd->ac)
            cmd_exec(curcmd);
        rmcmd(curcmd);
    }
    return sh->exc;
}

int main(int ac, char **av, char **env)
{
    sh_t sh = {mkdict(env), \
        {{0, O_RDONLY}, {1, O_WRONLY}, {2, O_WRONLY}}, \
        0, false};
    int ret = loop(ac, av, &sh);

    rmdict(sh.env);
    return ret;
}
