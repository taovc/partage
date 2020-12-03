/*
** EPITECH PROJECT, 2020
** my_str_isalpha.c
** File description:
** is
*/

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] < 65 || str[i] > 90) && (str[i] < 97 || str[i] > 122))
            return (0);
        i++;
    }
    return (1);
}
