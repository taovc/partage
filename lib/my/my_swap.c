/*
** EPITECH PROJECT, 2020
** my_swap.c
** File description:
** swap
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
