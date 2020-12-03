/*
** EPITECH PROJECT, 2020
** my_str_isprintable.c
** File description:
** my
*/

#include "my.h"

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32)
            return (0);
        i++;
    }
    return (1);
}
