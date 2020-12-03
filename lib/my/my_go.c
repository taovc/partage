/*
** EPITECH PROJECT, 2020
** go
** File description:
** go
*/

#include "my.h"
#include "print.h"

void my_put_nbr_hexa_2(va_list ap)
{
    my_put_nbr_hexa(va_arg(ap, int));
}

void my_put_nbr_hexa_3(va_list ap)
{
    my_put_nbr_hexa_l(va_arg(ap, int));
}

void my_put_nbr_bin_2(va_list ap)
{
    my_put_nbr_bin(va_arg(ap, unsigned int));
}

void my_put_ad_2(va_list ap)
{
    my_putstr("0x");
    my_put_nbr_hexa_l(va_arg(ap, int));
}

void my_put_nbr_3(va_list ap)
{
    my_put_nbr_4(va_arg(ap, unsigned int));
}
