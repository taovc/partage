/*
** EPITECH PROJECT, 2020
** myadd
** File description:
** add
*/

#include "my.h"

void pint(int i, int *c, int k)
{
    for (i = k - 1; i >= 0; i--) {
        my_put_nbr(c[i]);
    }
}

void add(char *a, char *b, int *c)
{
    int i, j, k = 0, r = 0, lena = my_strlen(a), lenb = my_strlen(b);

    for (i = lena - 1, j = lenb - 1; i >= 0 && j >= 0; i--, j--) {
        int p = (a[i] - '0') + (b[j] - '0') + r;
        r = p / 10;
        c[k++] = p % 10;
    }
    for (; i >= 0; i--) {
        int p = (a[i] - '0') + r;
        r = p / 10;
        c[k++] = p % 10;
    }
    for (; j >= 0; j--) {
        int p = (b[j] - '0') + r;
        r = p / 10;
        c[k++] = p % 10;
    }
    if (r)
        c[k++] = r;
    pint(i, c, k);
}
