/*
** EPITECH PROJECT, 2020
** connection
** File description:
** Connection beetween the 2 pid
*/

#include "my.h"
#include <signal.h>
#include "navy.h"
#include "print.h"

extern glo *glb;

int play_one_wait1(char atk[], map *player)
{
    for (int i = 0; i < 4; i++, atk[i] = 0);
    my_printf("my_pid: %d\nwaiting for enemy connection...\n", glb->pid1);
    while (glb->sleep_or_not == 0)
        usleep(100);
    my_printf("\nenemy connected\n");
    kill(glb->pid2, SIGUSR1);
    print_map(player);
    return 0;
}

int play_two_wait1(char **av, char atk[], map *player)
{
    for (int i = 0; i < 4; i++, atk[i] = 0);
    if (kill(my_getnbr(av[1]), SIGUSR1) != 0)
        return 84;
    my_printf("my_pid: %d\n", glb->pid1);
    while (glb->sleep_or_not == 0)
        usleep(100);
    my_printf("successfully connected\n");
    print_map(player);
    return 0;
}