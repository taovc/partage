/*
** EPITECH PROJECT, 2020
** mysub.c
** File description:
** mysub
*/

#include "my.h"

int ba(char *a, char *b, int lena, int lenb)
{
    int nb = 0;

    if (lenb > lena)
        return 1;
    if (lenb < lena)
        return 0;
    while (a[nb] == b[nb] && a[nb] != '\0' && b[nb] != '\0')
        nb++;
    if (b[nb] > a[nb])
        return 1;
    if (b[nb] == a[nb])
        return 2;
    else
        return 0;
}

void subba(char *a, char *b, int *c)
{
    int lena = my_strlen(a), lenb = my_strlen(b);
    int i, j, r = 0, n = 10, k = 0;

    for (i = lena - 1, j = lenb - 1; i >= 0 && j >= 0; i--, j--) {
        int p = (b[j] - '0') - (a[i] - '0') + r + n;
        r = ((p / 10) ? (r = 0) : (r = -1));
        c[k++] = p % 10;
    }
    for (; j >= 0; j--) {
        int p = (b[j] - '0') + r + n;
        r = ((p / 10) ? (r = 0) : (r = -1));
        c[k++] = p % 10;
    }
    for (i = k - 1; c[i] == 0 && i != 0; i--);
    for (; i >= 0; i--) {
        my_put_nbr(c[i]);
    }
}

int sub(char *a, char *b, int *c)
{
    int lena = my_strlen(a), lenb = my_strlen(b);

    if (ba(a, b, lena, lenb) == 2) {
        my_putchar('0');
        return 0;
    }
    if (ba(a, b, lena, lenb)) {
        subba(a, b, c);
        return 0;
    }
    if (ba(b, a, lenb, lena)){
        subba(b, a, c);
        return 0;
    }
}
