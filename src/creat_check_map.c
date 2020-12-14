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

extern glo *glb;

int check_pos2(char * str, int res)
{
    for (int i = 2; i <= 26; i += 8)
        (str[i] < 'A' && str[i] > 'H') ? (res = 84) : 0;
    for (int i = 5; i <= 29; i += 8)
        (str[i] < 'A' && str[i] > 'H') ? (res = 84) : 0;
    for (int i = 3; i <= 27; i += 8)
        (str[i] < '1' && str[i] > '8') ? (res = 84) : 0;
    for (int i = 6; i <= 30; i += 8)
        (str[i] < '1' && str[i] > '8') ? (res = 84) : 0;
    for (int i = 2; i <= 26; i += 8)
        (str[i] != str[i + 3] && str[i + 1] != str[i + 4]) ? (res = 84) : 0;
    return res;
}

int check_pos(char *str)
{
    int res = 0;

    if (my_strlen(str) != 32)
        return 84;
    for (int i = 0, nb = 2; i <= 24 && nb <= 5; i += 8, nb++)
        (str[i] - '0' != nb) ? (res = 84) : 0;
    for (int i = 1; i <= 25; i += 8)
        (str[i] != ':') ? (res = 84) : 0;
    for (int i = 4; i <= 28; i += 8)
        (str[i] != ':') ? (res = 84) : 0;
    if (check_pos2(str, res) == 84)
        res = 84;
    return res;
}

char *setmap(int i, char *str, char **av)
{
    int fd = open(av[i], O_RDONLY), len = 0;
    struct stat buf;

    if (fd == -1)
        return NULL;
    stat(av[i], &buf);
    str = malloc(sizeof(char) * (buf.st_size + 1));
    len = read(fd, str, buf.st_size);
    if (len <= 0)
        return (NULL);
    return str;
}

void condition_map(char *str, char **map, map_nb *nb)
{
    (str[2] == str[5] && str[3] + nb->two <= str[6]) ?
    (map[str[3] - '1' + nb->two][str[2] - 'A'] = '2', nb->two++): 0;
    (str[3] == str[6] && str[2] + nb->two <= str[5]) ?
    (map[str[3] - '1'][str[2] - 'A' + nb->two] = '2', nb->two++): 0;
    (str[10] == str[13] && str[11] + nb->three <= str[14]) ?
    (map[str[11] - '1' + nb->three][str[10] - 'A'] = '3', nb->three++): 0;
    (str[11] == str[14] && str[10] + nb->three <= str[13]) ?
    (map[str[11] - '1'][str[10] - 'A' + nb->three] = '3', nb->three++): 0;
    (str[18] == str[21] && str[19] + nb->four <= str[22]) ?
    (map[str[19] - '1' + nb->four][str[18] - 'A'] = '4', nb->four++): 0;
    (str[19] == str[22] && str[18] + nb->four <= str[21]) ?
    (map[str[19] - '1'][str[18] - 'A' + nb->four] = '4', nb->four++): 0;
    (str[26] == str[29] && str[27] + nb->five <= str[30]) ?
    (map[str[27] - '1' + nb->five][str[26] - 'A'] = '5', nb->five++): 0;
    (str[27] == str[30] && str[26] + nb->five <= str[29]) ?
    (map[str[27] - '1'][str[26] - 'A' + nb->five] = '5', nb->five++): 0;
}

map *creat_map(map *player)
{
    map_nb *nb;

    nb = malloc(sizeof(map_nb));
    player->map1 = malloc(sizeof(char *) * 8);
    player->map2 = malloc(sizeof(char *) * 8);
    for (int i = 0; i <= 7; i++) {
        player->map1[i] = my_strdup("........");
        player->map2[i] = my_strdup("........");
    }
    for (int i = 0; i <= 7; i++)
        for (int j = 0; j <= 7 ; j++)
            condition_map(player->str, player->map1, nb);
    if (nb->two != 2 || nb->three != 3
        || nb->four != 4 || nb->five != 5)
        return NULL;
    free(nb);
    return player;
}