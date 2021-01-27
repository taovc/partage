/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "my.h"
#include "print.h"
#include "mini.h"
#include <stdio.h>

int use_commond(mini *ms)
{
    if (ms->exe != NULL) {
        if (fork() == 0)
            return execve(ms->exe, ms->cmmd, ms->env);
        else {
            wait(&ms->stat);
            (isatty(0) == 1) ? my_printf("$>") : 0;
        }
        if (match_str(ms->cmmd[0], "cd") == 0)
            chdir(ms->cmmd[1]);
    }
    return 1;
}

int main(int ac, char **av, char **env)
{
    mini *ms = creat_env(ac, av, env);
    int i = 0;
    size_t len;

    if (ms == NULL) {
        write(2, "error\n", 6);
        return 84;
    }
    if (isatty(0) == 1)
        my_printf("$>");
    while (getline(&ms->str, &len, stdin) != EOF) {
        ms->exe = getbinaire(ms, ms->str);
        if ((i = use_commond(ms)) != 1)
            return i;
        if (match_str(ms->cmmd[0], "exit") == 0 &&
            ms->cmmd[1] == NULL)
            return 0;
        /*if (match_str(ms->cmmd[0], "setenv") == 0) {
            ms->env = str_to_array(ms->cmmd[1], ms->env, ':');
            if (fork() == 0)
                return execve("/bin/env", ms->cmmd, ms->env);
            else {
                wait(&ms->stat);
                (isatty(0) == 1) ? my_printf("$>") : 0;
        }*/
        if (ms->exe == NULL) {
            write(2, "command not find\n", 17);
            my_printf("$>");
        }
        ms->exe = NULL, ms->cmmd = NULL;
    }
    return 0;
}