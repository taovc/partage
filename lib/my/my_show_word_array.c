/*
** EPITECH PROJECT, 2020
** my_show_word_array.c
** File description:
** my
*/

#include "my.h"

int my_show_word_array(char **tab)
{
    my_putstr(concat_params(my_arraylen(tab), tab));
}
