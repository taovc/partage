/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "my.h"
#include "print.h"
#include "mini.h"

char **str_to_arry_2(char *str, char ** arry, char a, sta *st)
{
    if (str[st->i] != a)
        st->lenx++;
    if (str[st->i] == a && st->lenx != 0) {
        arry[st->ay] = malloc(sizeof(char) * st->lenx);
        for (int z = 0; z < st->lenx; z++)
            arry[st->ay][z] = str[st->i - st->lenx + z];
        arry[st->ay][st->lenx] = '\0', st->lenx = 0, st->ay++;
    }
}

char **str_to_array(char *str, char **arry, char a)
{
    int leny = 0, flag = 0;
    sta *st;

    st = malloc(sizeof(sta));
    st->ay = 0, st->i = 0, st->lenx = 0;
    str[my_strlen(str) - 1] = a;
    printf("%s\n", str);
    for (int i = 0; str[i]; i++) {
        (str[i] != a) ? flag = 1 : 0;
        (str[i] == a && flag != 0) ? leny++, flag = 0 : 0;
    }
    arry = malloc(sizeof(char *) * leny);
    for (; str[st->i] && st->ay < leny; st->i++) {
        str_to_arry_2(str, arry, a, st);
    }
    free(st);
    arry[leny] = NULL;
    return arry;
}