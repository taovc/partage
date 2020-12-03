/*
** EPITECH PROJECT, 2020
** my_is_prime
** File description:
** my
*/

#include "my.h"

int my_is_prime(int nb)
{
    int i = 2;

    if ((nb % 2 == 0 && nb != 2) || nb <= 1)
        return (0);
    while (nb % i != 0 && i <= nb / 2) {
        i++;
    }
    if (nb % i != 0 || i == nb)
        return (1);
    return (0);
}
