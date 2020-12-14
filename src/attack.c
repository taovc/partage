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

void attack(char atk[], map *player)
{
    my_printf("\nattack: ");
        while (read(0, atk, 1000)) {
            if (check_atk(atk) == 0)
                break;
            for (int i = 0; i < 4; i++, atk[i] = 0);
        }
        send_pos(atk, player);
}