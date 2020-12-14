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

void loss_or_win(void)
{
    if (glb->win == 14)
        my_printf("\nI won\n\n");
    if (glb->loss == 14)
        my_printf("\nEnemy won\n\n");
}

int play_one(map *player)
{
    char atk[1000];

    if (play_one_wait1(atk, player) == 84)
        return 84;
    while (glb->win != 14 || glb->loss != 14) {
        attack(atk, player);
        if (glb->win == 14 || glb->loss == 14) {
            loss_or_win();
            break;
        }
        receive_pos(player);
        print_map(player);
    }
    return 0;
}

int play_two(map *player, char **av)
{
    char atk[1000];

    if (play_two_wait1(av, atk, player) == 84)
        return 84;
    while (glb->win != 14 || glb->loss != 14) {
        receive_pos(player);
        if (glb->win == 14 || glb->loss == 14) {
            loss_or_win();
            break;
        }
        attack(atk, player);
        print_map(player);
    }
    return 0;
}