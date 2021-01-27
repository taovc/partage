/*
** EPITECH PROJECT, 2020
** ptnbr3
** File description:
** prnbr3
*/

#include "my.h"
#include "print.h"

void condition(int i, va_list ap, char *str)
{
    if (str[i] == '%') {
        i++;
        pint_sp(str, i, ap);
    }
    else if (str[i - 1] == '#' && str[i - 2] && str[i - 2] == '%' &&
            (str[i] == 'x' || str[i] == 'o' || str[i] == 'X'))
        i += 0;
    else
        my_putchar(str[i]);
}

void pint_sp(char *str, int i, va_list ap)
{
    if (str[i] == '%') {
        my_putchar('%');
        return;
    }
    if (str[i] == '#' && str[i + 1] &&
        ((str[i + 1] == 'X') || (str[i + 1] == 'x'))) {
        my_putchar('0');
        my_putchar(str[i + 1]);
        check_str(ap, i + 1, str);
        return;
    }
    if (str[i] == '#' && str[i + 1] && str[i + 1] == 'o') {
        my_putchar('0');
        check_str(ap, i + 1, str);
        return;
    }
    if (str[i] != '%' && str[i] != '#')
        check_str(ap, i, str);
}

int my_put_nbr_4(unsigned int nb)
{
    if (nb <= 9)
        my_putchar(nb + 48);
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + 48);
    }
    return (0);
}
