/*
** EPITECH PROJECT, 2020
** my_str_islower.c
** File description:
** my
*/

#include "my.h"

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 65 && str[i] <= 90)
            return (0);
        i++;
    }
    return (1);
}
