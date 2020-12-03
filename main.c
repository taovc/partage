/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "my.h"
#include "print.h"
#include "psw.h"

int check_order(psw *list, int *str, int len)
{
    if (list->lena == 1)
        return 1;
    for (int i = 0; i < len - 1; i++)
        if (str[i] > str[i + 1])
            return 0;
    return 1;
}

void condition_psw(psw * list, int *a)
{
    if (list->a[0] > list->a[1] && list->a[0] <= list->a[list->lena - 1]) {
        str_sa(list->a);
        order_list(list, a);
    }
    if (list->a[0] > list->a[list->lena - 1]) {
        str_ra(list->a, list);
        order_list(list, a);
    }
    if (list->a[0] <= list->a[1] && list->a[0] <=
    list->a[list->lena - 1] && check_order(list, list->a, list->lena) != 1) {
        str_pb(list->a, list->b, list);
        order_list(list, a);
    }
    if (list->lenb != 0 && check_order(list, list->a, list->lena) == 1) {
        str_pa(list->a, list->b, list);
        order_list(list, a);
    }
}

int order_list(psw *list, int *a)
{
    if (check_order(list, list->a, list->lena) == 1 && list->lenb == 0)
        return 0;
    if (check_order(list, list->a, list->lena) != 1 ||
    (check_order(list, list->a, list->lena) == 1 && list->lenb != 0)) {
        (*a != 0) ? my_putstr("  ") : 0;
        *a += 1;
        condition_psw(list, a);
    }
    return 0;
}

int main(int ac, char **av)
{
    int count = 0;
    psw *list;

    if (check_av(ac, av) == 84)
        return 84;
    list = malloc(sizeof(psw));
    list->a= malloc(sizeof(int) * (ac + 1));
    list->b = malloc(sizeof(int) * (ac + 1));
    list->lena = ac - 1, list->lenb = 0;
    for (int i = 0; i < ac - 1; i++)
        list->a[i]  = my_getnbr(av[i + 1]);
    if (check_order(list, list->a, list->lena) == 1) {
        my_putchar('\n');
        return 0;
    }
    order_list(list, &count);
    for (int i = 0; i < list->lena; i++)
        my_printf("%d ", list->a[i]);
    //printf("%d %d", ac, list->lena);
    my_printf("\n");
    free(list->a);
    free(list->b);
    return 0;
}
