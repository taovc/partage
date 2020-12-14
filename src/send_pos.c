/*
** EPITECH PROJECT, 2020
** send_pos
** File description:
** Send signal to get position
*/

#include "my.h"
#include <signal.h>
#include "navy.h"
#include "print.h"

extern glo *glb;

map *check_hit_or_not_send(map *player)
{
    if (player->map1[glb->line][glb->column] >= '2'
        && player->map1[glb->line][glb->column] <= '5') {
        my_printf("%c%c: hit\n", glb->column + 'A', glb->line + '0' + 1);
        player->map1[glb->line][glb->column] = 'x';
        glb->loss++;
        kill(glb->pid2, SIGUSR1);
    } else {
        my_printf("%c%c: missed\n", glb->column + 'A', glb->line + '0' + 1);
        player->map1[glb->line][glb->column] = 'o';
        kill(glb->pid2, SIGUSR2);
    }
    return player;
}

void check_hit_or_not_receive(char atk[], map *player)
{
    glb->line--;
    glb->column--;
    glb->type = 2;
    while (glb->hit == 0)
        usleep(100);
    if (glb->hit == 1) {
        player->map2[glb->line][glb->column] = 'x';
        glb->win++;
        my_printf("%c%c : hit\n", atk[0], atk[1]);
    }
    if (glb->hit == 2) {
        player->map2[glb->line][glb->column] = 'o';
        my_printf("%c%c : missed\n", atk[0], atk[1]);
    }
}

void send_pos(char atk[], map *player)
{
    glb->sleep_or_not = 0, glb->hit = 0, glb->column = 0
    , glb->line = 0, glb->end = 0, glb->type = 2;
    for (int i = -1; i < (atk[0] - 'A'); i++) {
        kill(glb->pid2, SIGUSR1);
        glb->column++;
        usleep(10000);
    }
    for (int i = -1; i < (atk[1] - '1'); i++) {
        kill(glb->pid2, SIGUSR2);
        glb->line++;
        usleep(10000);
    }
    kill(glb->pid2, SIGUSR1);
    check_hit_or_not_receive(atk, player);
}

void receive_pos(map *player)
{
    my_printf("\nwaiting for enemy's attack...\n");
    glb->sleep_or_not = 0, glb->hit = 0, glb->column = 0
    , glb->line = 0, glb->end = 0, glb->type = 1;
    while (glb->sleep_or_not == 0)
        usleep(100);
    glb->column--, glb->line--;
    player = check_hit_or_not_send(player);
}