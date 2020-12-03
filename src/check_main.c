/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "my.h"
#include "print.h"
#include "psw.h"

int check_av_bf(int i, char **av)
{
    for (int j = 0; av[i][j]; j++)
        if ((av[i][j] > '9' || av[i][j] < '0')
            && (av[i][j] != '-' || j != 0))
            return 84;
    return 0;
}

int check_av(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
        if (check_av_bf(i, av) == 84)
            return 84;
    return 0;
}

int *str_sa(int *str_a)
{
    int temp;

    temp = str_a[0];
    str_a[0] = str_a[1];
    str_a[1] = temp;
    my_putstr("sa");
    return str_a;
}

int *str_sb(int *str_b)
{
    int temp;

    temp = str_b[0];
    str_b[0] = str_b[1];
    str_b[1] = temp;
    my_putstr("sb");
    return str_b;
}