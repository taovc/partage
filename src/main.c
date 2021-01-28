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
            if (ms->cmmd[1] != NULL)
                chdir(ms->cmmd[1]);
    }
    return 1;
}

int change_env(char *str, mini *ms)
{
    if (fork() == 0)
        return execve(str, ms->cmmd, ms->env);
    else {
        wait(&ms->stat);
        (isatty(0) == 1) ? my_printf("$>") : 0;
    }
    return 1;
}

void add_line_env(mini *ms)
{
    int i = 0, len = 0;
    char **arr = NULL;

    for (i = 0; ms->env[i]; i++);
    arr = malloc(sizeof(char *) * i + 1);
    arr = cp_array(arr, ms->env);
    len = my_strlen(ms->cmmd[1]) + my_strlen(ms->cmmd[2]);
    arr[i] = my_memset(arr[i], len);
    arr[i] = my_strcat(arr[i], ms->cmmd[1]);
    arr[i] = my_strcat(arr[i], "=");
    arr[i] = my_strcat(arr[i], ms->cmmd[2]);
    arr[i + 1] = NULL;
    ms->env = arr;
}

void change_line_env_2(mini *ms, char *str, int i, char **arr)
{
    int len = 0, j = 0;

    if (my_strncmp(ms->env[i], str, my_strlen(str) - 1) != 0) {
        for (len = 0; ms->env[i][len]; len++);
        arr[j] = malloc(sizeof(char) * len);
        for (len = 0; ms->env[i][len]; len++)
            arr[j][len] = ms->env[i][len];
        arr[j][len] = '\0';
        j++;
    }
}

void change_line_env(mini *ms, char *str)
{
    int i = 0, len = 0, j = 0;
    char **arr = NULL;

    for (i = 0; ms->env[i]; i++);
    arr = malloc(sizeof(char *) * i);
    for (int i = 0; ms->env[i] != NULL; i++) {
        if (my_strncmp(ms->env[i], str, my_strlen(str) - 1) != 0) {
        for (len = 0; ms->env[i][len]; len++);
        arr[j] = malloc(sizeof(char) * len);
        for (len = 0; ms->env[i][len]; len++)
            arr[j][len] = ms->env[i][len];
        arr[j][len] = '\0';
        j++;
    }
    }
    len = my_strlen(ms->cmmd[1]) + my_strlen(ms->cmmd[2]);
    arr[i] = my_memset(arr[i], len);
    arr[j] = my_strcat(arr[j], ms->cmmd[1]);
    arr[j] = my_strcat(arr[j], "=");
    arr[j] = my_strcat(arr[j], ms->cmmd[2]);
    arr[j + 1] = NULL;
    ms->env = arr;
}

int add_env(mini *ms)
{
    if (find_env(ms, ms->cmmd[1], my_strlen(ms->cmmd[1])) == NULL)
        add_line_env(ms);
    if (find_env(ms, ms->cmmd[1], my_strlen(ms->cmmd[1])) != NULL)
        change_line_env(ms, ms->cmmd[1]);
    my_printf("$>");
    return 0;
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
        if (ms->exe == NULL) {
            if (strncmp(ms->str, "setenv", 6) == 0) {
                ms->cmmd = str_to_array(ms->str, ms->cmmd, ' ');
                if (match_str(ms->cmmd[0], "setenv") == 0) {
                    (ms->cmmd[1] == NULL) ? change_env("/bin/env", ms) : 0;
                    (ms->cmmd[1] != NULL) ? add_env(ms) : 0; 
                }
            }
            else {
            write(2, "command not find\n", 17);
            my_printf("$>");
            }
        }
        ms->cmmd = NULL;
    }
    return 0;
}