/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "my.h"
#include "print.h"
#include "psw.h"

int *revome(int *str, int len)
{
    int i = 0, a = len;

    for (i = 0; i < a; i++)
        str[i] = str[i + 1];
    return str;
}

int *add_char(int *str, int len)
{
    int i = 0;
    int str2[len];

    for (int i = 0; i < len; i++)
        str2[i] = str[i];
    for (i = 0; i < len; i++) {
        str[i + 1] = str2[i];
    }
    return str;
}

int *str_pb(int *str_a, int *str_b, psw *list)
{
    list->lena--;
    list->lenb++;
    str_b = add_char(str_b, list->lenb);
    str_b[0] = str_a[0];
    str_a = revome(str_a, list->lena);
    my_putstr("pb");
    return str_b;
}

int *str_pa(int *str_a, int *str_b, psw *list)
{
    list->lena++;
    list->lenb--;
    str_a = add_char(str_a, list->lena);
    str_a[0] = str_b[0];
    str_b = revome(str_b, list->lenb);
    my_putstr("pa");
    return str_a;
}

int *str_ra(int *str_a, psw *list)
{
    int a = list->lena;
    int tmp = str_a[0];

    str_a = revome(str_a, list->lena);
    str_a[a - 1] = tmp;
    my_putstr("ra");
    return str_a;
}
