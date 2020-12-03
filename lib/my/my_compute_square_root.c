/*
** EPITECH PROJECT, 2020
** my_compute_square_root.c
** File description:
** square_root
*/

int my_compute_square_root(int nb)
{
    int i = 1;
    int i_result = 0;

    while (i_result < nb) {
        i_result = i * i;
        if (i_result == nb) {
            return (i);
        } else if (i > 46340) {
            return (0);
        } else {
            i = i + 1;
        }
    }
    return (0);
}
