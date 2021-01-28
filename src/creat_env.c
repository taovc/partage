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

char *find_env_2(char **env, mini *ms, int i, int len)
{
    int k = 0;

    ms->line = malloc(sizeof(char) * (my_strlen(env[i]) - len));
    for (; env[i][len]; ms->line[k] = env[i][len], k++, len++);
    ms->line[k + 1] = '\0';
    return ms->line;
}

char *find_env(mini *ms, char *str, int len)
{
    int i = 0;

    ms->line = NULL;
    while (ms->env[i] != NULL) {
        if (strncmp(ms->env[i], str, len) == 0)
            ms->line = find_env_2(ms->env, ms, i, len);
        i++;
    }
    return ms->line;
}

char **cp_array(char **dest, char **array)
{
    int y = 0, len = 0;

    for (; array[y] != NULL; y++);
    dest = malloc(sizeof(char *) * y);
    for (int i = 0; array[i] != NULL; i++) {
        for (len = 0; array[i][len]; len++);
        dest[i] = malloc(sizeof(char) * len);
        for (len = 0; array[i][len]; len++)
            dest[i][len] = array[i][len];
        dest[i][len] = '\0';
    }
    dest[y] = NULL;
    return dest;
}

mini *creat_env(int ac, char **av, char **env)
{
    mini *ms;

    if (ac != 1 || av[1] != NULL)
        return NULL;
    signal(SIGINT, SIG_IGN);
    ms = malloc(sizeof(mini));
    ms->str = NULL;
    ms->exe = NULL;
    ms->env = cp_array(ms->env, env);
    ms->path = find_env(ms, "PATH=\0", 5);
    if (ms->path == NULL)
        ms->path = my_strdup("/home/vc/.local/bin:/home/vc/bin:"
        "/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin\0");
    ms->bina = str_to_array(ms->path, ms->bina, ':');
    prt_arry(ms->bina);
    return ms;
}