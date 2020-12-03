/*
** EPITECH PROJECT, 2020
** my_strlowcase.c
** File description:
** lowcase
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] <= 90 && str[i] >= 65) {
            str[i] = str[i] + 32;
        }
        i++;
    }
    return (str);
}
