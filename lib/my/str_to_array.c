/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "my.h"
#include "print.h"
#include "mini.h"

void str_to_array_2(char *str, char **array, char a, sta *st)
{
    int len = st->len;

    if ((str[st->indx] == a || st->indy == st->leny) && st->flag != 0) {
        st->flag = 0;
        array[st->indy] = my_memset(array[st->indy], st->len + 1);
        for (int k = 0; k < st->len;
            array[st->indy][k] = str[st->indx - st->len + k], k++);
        array[st->indy][st->len + 1] = '\0';
        st->len = 0, st->indy++;
    }
}

char **str_to_array(char *str, char **array, char a)
{
    sta *st;
    char *str2 = my_memset(str2, my_strlen(str));

    for (int i = 0; str[i]; str2[i] = str[i], i++);
    str2[my_strlen(str) - 1] = a, st = malloc(sizeof(sta)), st->leny = 0;
    for (int i = 0, flag = 0; str2[i]; i++) {
        (str2[i] != a) ? flag = 1 : 0;
        (str2[i] == a && flag != 0) ? st->leny++, flag = 0 : 0;
    }
    array = malloc(sizeof(char *) * st->leny);
    st->indx = 0, st->flag = 0, st->indy = 0, st->len = 0;
    for (; st->indy <= st->leny && str2[st->indx]; st->indx++) {
        if (str2[st->indx] != a && str2[st->indx]) {
            st->flag = 1, st->len++;
            continue;
        }
        str_to_array_2(str2, array, a, st);
    }
    array[st->leny] = NULL, free(str2), free(st);
    return array;
}