/*
** EPITECH PROJECT, 2020
** my_arraylen.c
** File description:
** arraylen
*/

#include "my.h"

int my_arraylen(char **str)
{
    int i = 0;

    while (str[i]) {
        i = i + 1;
    }
    return (i);
}
