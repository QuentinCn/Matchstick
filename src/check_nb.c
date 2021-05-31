/*
** EPITECH PROJECT, 2021
** check_nb.c
** File description:
** check the string pass as input
*/

#include "my.h"

static int check_char(char *nb, char *str, int max)
{
    for (int i = 0; nb[i] != '\0'; i += 1)
        if (!((nb[i] >= '0' && nb[i] <= '9') || nb[i] == '\n')) {
            my_putstr("Error: invalid input (positive number expeted)\n");
            if (str[0] == 'M')
                return -2;
            else
                return get_info(str, max);
        }
    return 0;
}

int check_in_map(char **map, int line, int nb_stick)
{
    int nb_pipe = 0;

    for (int i = 0; map[line][i] != '\0'; i += 1)
        if (map[line][i] == '|')
            nb_pipe += 1;
    if (nb_stick > nb_pipe) {
        my_putstr("Error: not enough matches on this line\n");
        return -2;
    }
    return nb_stick;
}

int check_nb(char *nb, char *str, int max)
{
    int check = -1;

    check = check_char(nb, str, max);
    if (check != 0)
        return check;
    if (my_getnbr(nb) <= max && my_getnbr(nb) > 0)
        return my_getnbr(nb);
    if (str[0] == 'L')
        my_putstr("Error: this line is out of range\n");
    else {
        if (my_getnbr(nb) == 0)
            my_putstr("Error: you have to remove at least one match\n");
        else {
            my_putstr("Error: you cannot remove more than ");
            my_put_nbr(max);
            my_putstr(" matches per turn\n");
        }
        return -2;
    }
    return get_info(str, max);
}
