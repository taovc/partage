/*
** EPITECH PROJECT, 2021
** prinarry
** File description:
** printarry
*/

#include "my.h"

void prt_arry(char **arry)
{
    for (int i = 0; arry[i]; i++) {
        my_putstr(arry[i]);
        my_putchar('\n');
    }
}