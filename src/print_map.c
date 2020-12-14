/*
** EPITECH PROJECT, 2020
** player
** File description:
** player
*/

#include "my.h"
#include <signal.h>
#include "navy.h"
#include "print.h"

extern glo *glb;

void print_map(map *player)
{
    my_printf("\nmy positions:\n |A B C D E F G H\n-+---------------\n");
    for (int i = 0, nbr = 1; i <= 7; i++, nbr++) {
        my_printf("%c|", nbr + '0');
        for (int j = 0; j <= 7; j++) {
            my_printf("%c", player->map1[i][j]);
            (j != 7) ? my_printf(" ") : 0;
        }
        my_printf("\n");
    }
    my_printf("\nenemy's positions:\n |A B C D E F G H\n-+---------------\n");
    for (int i = 0, nbr = 1; i <= 7; i++, nbr++) {
        my_printf("%c|", nbr + '0');
        for (int j = 0; j <= 7; j++) {
            my_printf("%c", player->map2[i][j]);
            (j != 7) ? my_printf(" ") : 0;
        }
        my_printf("\n");
    }
}

int check_atk(char atk[])
{
    int error = 0;

    if (atk[0] > 'H' || atk[0] < 'A')
        error = 84;
    if (atk[1] > '8' || atk[1] < '1')
        error =  84;
    if (atk[2] != '\n')
        error = 84;
    if (atk[3] != 0)
        error = 84;
    (error == 84) ? my_printf("wrong position\nattack: ") : 0;
    return error;
}
