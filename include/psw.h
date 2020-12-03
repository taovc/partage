/*
** EPITECH PROJECT, 2020
** my_strncpy.c
** File description:
** my_strncpy
*/


typedef struct flag_psw
{
    int *a;
    int *b;
    int lena;
    int lenb;
} psw;

int check_av_bf(int i, char **av);
int check_av(int ac, char **av);
int *str_sa(int *str_a);
int *str_sb(int *str_b);
int *revome(int *str, int len);
int *add_char(int *str, int len);
int *str_pa(int *str_a, int *str_b, psw *list);
int *str_pb(int *str_a, int *str_b, psw *list);
int *str_ra(int *str_a, psw *list);
int order_list(psw *list, int *a);
void condition_psw(psw * list, int *a);