/*
** EPITECH PROJECT, 2020
** fc 2
** File description:
** fc2
*/

#include "my.h"
#include "print.h"

void my_put_nbr_octal(unsigned int nb)
{
    unsigned int len;

    len = 8;
    if (nb >= len - 1)
        my_put_nbr_octal(nb / len);
    my_putchar(octal[nb % len]);
}

void my_put_bis(char *str)
{
    int start;

    start = 0;
    while (str[start] != '\0') {
        if (str[start] < 32 || str[start] >= 127) {
            my_putstr("\\0");
            my_put_nbr_octal((int)str[start]);
            start++;
        } else {
            my_putchar(str[start]);
            start++;
        }
    }
}

void my_put_nbr_hexa(unsigned int nb)
{
    unsigned int len;
    char str[20];
    int i = 19, tmp = nb;

    len = 16;
    while (nb >= len - 1) {
        str[i] = (hexa[nb % len]);
        nb = nb / len, i--;
    }
    str[i] = (hexa[nb % len]);
    if (tmp < 0) {
        for (int j = 19; i <= j; i++)
            (str[i] != '0') ? my_putchar(str[i]) : 0;
    }
    for (int j = 19; i <= j; i++)
        my_putchar(str[i]);
}

void my_put_nbr_hexa_l(unsigned int nb)
{
    unsigned int len;
    char str[20];
    int i = 19, tmp = nb;

    len = 16;
    while (nb >= len - 1) {
        str[i] = (ab[nb % len]);
        nb = nb / len, i--;
    }
    str[i] = (ab[nb % len]);
    if (tmp < 0) {
        for (int j = 19; i <= j; i++)
            (str[i] != '0') ? my_putchar(str[i]) : 0;
    }
    for (int j = 19; i <= j; i++)
        my_putchar(str[i]);
}

int my_put_nbr_bin(unsigned int nb)
{
    unsigned int len;

    len = 2;
    if (nb > 1)
        my_put_nbr_bin(nb / len);
    my_putchar(bin[nb % len]);
    return 0;
}
