/*
** EPITECH PROJECT, 2020
** MINI
** File description:
** Contains all the functions for the mini
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h> 
#include <sys/wait.h>

#ifndef H_MINI_H_
#define H_MINI_H_

typedef struct mini
{
    char *path;
    char *exe;
    char **env;
    char **cmmd;
    char *str;
    int stat;
    size_t len;
} mini;

int match_str(char *str, char *str2);
char *find_match(mini *ms, char *str);
char *find_ex(mini *ms, char *str);
char *getbinaire(mini *ms, char *str);
void creat_path_2(char **env, mini *ms, int i);
void creat_path(char **env, mini *ms);
mini *creat_env(int ac, char **av, char **env);
#endif /* H_MINI_H_ */
