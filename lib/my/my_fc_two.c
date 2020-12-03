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
            my_putstr("\\00");
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

    len = 16;
    if (nb >= len - 1)
        my_put_nbr_hexa(nb / len);
    my_putchar(hexa[nb % len]);
}

void my_put_nbr_hexa_l(unsigned int nb)
{
    unsigned int len;

    len = 16;
    if (nb >= len - 1)
        my_put_nbr_hexa_l(nb / len);
    my_putchar(ab[nb % len]);
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
