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
    int len = my_strlen(str) + my_strlen(ms->cmmd[0]);

    ms->exe = my_memset(ms->exe, len);
    ms->exe = my_strcat(ms->exe, str);
    ms->exe = my_strcat(ms->exe, "/");
    ms->exe = my_strcat(ms->exe, ms->cmmd[0]);
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
            printf("%s\n", ms->exe);
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
    prt_arry(ms->cmmd);
    ms->path = find_env(ms, "PATH=", 5);
    //if (ms->path == NULL)
    //    ms->path = my_strdup("/home/vc/.local/bin:/home/vc/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin");
    ms->bina = str_to_array(ms->path, ms->bina, ':');
    ms->exe = NULL;
    for (int z = 0; ms->bina[z] != NULL; z++)
        if (ms->exe == NULL)
            ms->exe = find_ex(ms, ms->bina[z]);
    return ms->exe;
}
