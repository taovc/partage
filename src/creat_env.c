/*
** EPITECH PROJECT, 2021
** creat_env.c
** File description:
** creat_env
*/

#include "my.h"
#include "print.h"
#include "mini.h"
#include <stdio.h>

void creat_path_2(char **env, mini *ms, int i)
{
    int j = 5;

    if (env[i][0] == 'P' && env[i][1] == 'A'
        && env[i][2] == 'T' && env[i][3] == 'H' && env[i][4] == '=') {
        ms->path = malloc(sizeof(char) * (my_strlen(env[i]) - 5));
        for (int k = 0; env[i][j]; ms->path[k] = env[i][j], k++, j++);
    }
}

void creat_path(char **env, mini *ms)
{
    for (int i = 0; env[i]; i++)
        creat_path_2(env, ms, i);
}

mini *creat_env(int ac, char **av, char **env)
{
    mini *ms;

    if (ac != 1 || av[1] != NULL)
        return NULL;
    signal(SIGINT, SIG_IGN);
    ms = malloc(sizeof(mini));
    ms->str = NULL;
    creat_path(env, ms);
    ms->env = str_to_array(ms->path, ms->env, ':');
    return ms;
}