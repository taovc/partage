/*
** EPITECH PROJECT, 2020
** my_charisalpha.c
** File description:
** m
*/

#include "my.h"

int my_charisalpha(char const str)
{
    if ((str < 65 || str > 90) && (str < 97 || str > 122))
        return (0);
    return (1);
}
