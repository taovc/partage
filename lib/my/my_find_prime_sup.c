/*
** EPITECH PROJECT, 2020
** my_find_prime_sup.c
** File description:
** to_find_prime
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    if (nb < 0)
        nb = 0;
    while (my_is_prime(nb) == 0) {
        my_is_prime(nb + 1);
        nb = nb + 1;
    }
    return (nb);
}
