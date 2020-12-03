/*
** EPITECH PROJECT, 2020
** my_strncat.c
** File description:
** strncats
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int dest_len = my_strlen(dest);

    while (src[i] != '\0' && i < nb) {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return (dest);
}
