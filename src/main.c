/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "my.h"
#include <signal.h>
#include "navy.h"
#include "print.h"

glo *glb;

char *swap_char(char *str, int a, int b)
{
    char tmp = str[a];

    str[a] = str[b];
    str[b] = tmp;
    return str;
}

char *setmap2(char *str)
{
    for (int i = 0; i <= 24; i += 8) {
        if (str[2 + i] == str[5 + i] && str[3 + i] > str[6 + i])
            swap_char(str, 3 + i, 6 + i);
        if (str[3 + i] == str[6 + i] && str[2 + i] > str[5 + i])
            swap_char(str, 2 + i, 5 + i);
    }
    return str;
}

int connect(map *player, int ac, char **av)
{
    if (ac == 2) {
        player->str = setmap(1, player->str, av);
        if (player->str == NULL || check_pos(player->str) == 84)
            return 84;
        player->str = setmap2(player->str);
        player = creat_map(player);
        if (player->map1 == NULL || play_one(player) == 84)
            return 84;
    }
    if (ac == 3) {
        player->str = setmap(2, player->str, av);
        if (player->str == NULL || check_pos(player->str) == 84)
            return 84;
        player->str = setmap2(player->str);
        player = creat_map(player);
        if (player->map1 == NULL || play_two(player, av) == 84)
            return 84;
    }
    return 0;
}

int main(int ac, char **av)
{
    map *player;

    player = malloc(sizeof(map));
    stup_glo();
    if (connect(player, ac, av) == 84)
        return 84;
    if (ac != 2 && ac != 3)
        return 84;
    return 0;
}