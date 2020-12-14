/*
** EPITECH PROJECT, 2020
** h_navy
** File description:
** Contains all the functions for the navy
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#ifndef H_NAVY_H_
#define H_NAVY_H_

typedef struct global {
    pid_t pid1;
    pid_t pid2;
    int type;
    int column;
    int line;
    int sleep_or_not;
    int end;
    int hit;
    int win;
    int loss;
}glo;

typedef struct aled {
    char **map1;
    char **map2;
    char *str;
}map;

typedef struct alede {
    int two;
    int three;
    int four;
    int five;
}map_nb;

void stup_glo(void);
int play_one(map *player);
int play_two(map *player, char **av);
int play_one_wait1(char atk[], map *player);
int play_two_wait1(char **av, char atk[], map *player);
map *creat_map(map *player);
void print_map(map *player);
int check_atk(char atk[]);
void condition_map(char *str, char **map, map_nb *nb);
char *setmap(int i, char *str, char **av);
int check_pos(char *str);
int check_pos2(char * str, int res);
void send_pos(char atk[], map *player);
void receive_pos(map *player);
void check_hit_or_not_receive(char atk[], map *player);
map *check_hit_or_not_send(map *player);
void attack(char atk[], map *player);

#endif /* H_NAVY_H_ */
