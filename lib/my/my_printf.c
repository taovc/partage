/*
** EPITECH PROJECT, 2020
** my
** File description:
** my
*/

#include <stdio.h>
#include "print.h"
#include "my.h"

flags flag[] =
{
    {'u', &my_put_nbr_3},
    {'i', &my_put_nbr_2},
    {'d', &my_put_nbr_2},
    {'c', &my_putchar_2},
    {'s', &my_putstr_2},
    {'S', &my_put_bis_2},
    {'b', &my_put_nbr_bin_2},
    {'X', &my_put_nbr_hexa_2},
    {'x', &my_put_nbr_hexa_3},
    {'o', &my_put_nbr_octal_2},
    {'p', &my_put_ad_2},
};

void check_str(va_list ap, int i, char *str)
{
    int b = 12;
    int a;

    for (a = 0; a < b && flag[a].c != str[i]; a++);
    if (a == b) {
        my_putchar('%');
        my_putchar(str[i]);
    } else
        flag[a].fc(ap);
}

void my_printf(char *str, ...)
{
    va_list ap;
    int i = -1;

    va_start(ap, str);
    while (str[++i]) {
        condition(i, ap, str);
        if (str[i] == '%')
            i++;
    }
    va_end(ap);
}
