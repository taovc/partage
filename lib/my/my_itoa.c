/*
** EPITECH PROJECT, 2020
** my_itoa.c
** File description:
** change_int_to_string
*/

#include <stdlib.h>
#include "my.h"

char *my_itoa(int n)
{
    int i = 0, neg = 0;
    static char s[100];

    for(int i = 0; i < 99; i++)
        s[i] = '\0';
    if (n == 0) {
        s[0] = '0';
        return s;
    }
    (n < 0) ? (neg = -1, n *= -1) : 0;
    while (n > 0) {
        s[i] = n % 10 + '0';
        n /= 10;
        i++;
    }
    if (neg == -1)
        s[i] = '-';
    s[++i] = '\0';
    return my_revstr(s);
}