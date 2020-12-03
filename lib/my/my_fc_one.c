/*
** EPITECH PROJECT, 2020
** fc_one
** File description:
** putnbr2
*/

#include "my.h"
#include "print.h"

void my_putchar_2(va_list ap)
{
    my_putchar(va_arg(ap, int));
}

void my_put_nbr_2(va_list ap)
{
    my_put_nbr(va_arg(ap, int));
}

void my_putstr_2(va_list ap)
{
    my_putstr(va_arg(ap, char *));
}

void my_put_nbr_octal_2(va_list list)
{
    my_put_nbr_octal(va_arg(list, int));
}

void my_put_bis_2(va_list ap)
{
    my_put_bis(va_arg(ap, char *));
}
