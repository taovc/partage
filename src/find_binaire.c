/*
** EPITECH PROJECT, 2021
** find_binaire.c
** File description:
** find_binaire
*/

#include "my.h"
#include "print.h"
#include "mini.h"
#include <stdio.h>

int match_str(char *str, char *str2)
{
    int len1 = my_strlen(str);
    int len2 = my_strlen(str2);

    if (len1 != len2)
        return -1;
    for (int i = 0; i < len1 && str[i] && str2[i]; i++)
        if (str[i] != str2[i])
            return -1;
    return 0;
}

char *find_match(mini *ms, char *str)
{
    ms->exe = my_memset(ms->exe,
        my_strlen(str) + my_strlen(ms->cmmd[0]));
    for (int j = 0; str[j]; ms->exe[j] = str[j], j++);
    ms->exe[my_strlen(str)] = '/';
    for (int z = my_strlen(str) + 1, k = 0; ms->cmmd[0][k];
        ms->exe[z + k] = ms->cmmd[0][k], k++);
    return ms->exe;
}

char *find_ex(mini *ms, char *str)
{
    DIR *dir;
    struct dirent *direntp;
    struct stat buf;

    dir = opendir(str);
    if (dir == NULL)
        return NULL;
    direntp = readdir(dir);
    while (direntp != NULL) {
        stat(str, &buf);
        if (buf.st_mode & S_IXUSR &&
            match_str(direntp->d_name, ms->cmmd[0]) == 0) {
            ms->exe = find_match(ms, str);
            return ms->exe;
        }
        direntp = readdir(dir);
    }
    closedir(dir);
    return NULL;
}

char *getbinaire(mini *ms, char *str)
{
    if (my_strlen(str) <= 2) {
        ms->exe = NULL;
        return ms->exe;
    }
    ms->cmmd = str_to_array(str, ms->cmmd, ' ');
    for (int z = 0; ms->env[z] != NULL; z++)
        if (ms->exe == NULL)
            ms->exe = find_ex(ms, ms->env[z]);
    return ms->exe;
}
