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

int check_all_print2(char *str)
{
    int j = 0, len = 0;

    for (int i = 0; str[i]; i++, len++) {
        (str[i] == '%') ? j = 1, len = 0 : 0;
        if ((str[i] == 'x' || str[i] == 'X' || str[i] == 'o')
            && j == 1 && (len != 1 && len != 2))
            return 84;
        if (len == 2 && str[i - 1] != '#' && j == 1 &&
            (str[i] == 'x' || str[i] == 'X' || str[i] == 'o'))
            return 84;
        if ((str[i] == 'x' || str[i] == 'X' || str[i] == 'o')
            && j == 1)
            j = 0, len = 0;
        if ((str[i] == 'x' || str[i] == 'X' || str[i] == 'o')
            && ((str[i - 1] == '%' && str[i - 2] == '%')
            || (str[i - 1] == '#' && str[i - 2] == '%' && str[i - 3] == '%')))
            return 84;
    }
    return 0;
}

int check_all_print(char *str)
{
    int j = 0, len = 0;

    for (int i = 0; str[i]; i++, len++) {
        (str[i] == '%') ? j = 1, len = 0 : 0;
        if ((str[i] == 'd' || str[i] == 'u' || str[i] == 'i'
            || str[i] == 'c' || str[i] == 's' || str[i] == 's'
            || str[i] == 'S' || str[i] == 'b' || str[i] == 'p')
            && j == 1 && len != 1)
            return 84;
        if ((str[i] == 'd' || str[i] == 'u' || str[i] == 'i'
            || str[i] == 'c' || str[i] == 's' || str[i] == 's'
            || str[i] == 'S' || str[i] == 'b' || str[i] == 'p') && j == 1)
            j = 0, len = 0;
        if ((str[i] == 'd' || str[i] == 'u' || str[i] == 'i'
            || str[i] == 'c' || str[i] == 's' || str[i] == 's'
            || str[i] == 'S' || str[i] == 'b' || str[i] == 'p')
            && str[i - 1] == '%' && str[i - 2] == '%')
            return 84;
    }
    return 0;
}

void my_printf(char *str, ...)
{
    va_list ap;
    int i = -1;

    va_start(ap, str);
    if (check_all_print(str) == 84 || check_all_print2(str) == 84)
        return;
    while (str[++i]) {
        condition(i, ap, str);
        if (str[i] == '%')
            i++;
    }
    va_end(ap);
}