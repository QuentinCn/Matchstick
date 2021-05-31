/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main of matchstick
*/

#include "my.h"
#include <stddef.h>

int main(int ac, char const * const av[])
{
    char **map = NULL;
    int win = 0;

    if (!handle_error(ac, av))
        return 84;
    map = create_map(my_getnbr(av[1]));
    win = play(map, my_getnbr(av[1]), my_getnbr(av[2]));
    if (win == 1)
        my_putstr("I lost... snif... but I'll get you next time!!\n");
    else if (win == 2)
        my_putstr("You lost, too bad...\n");
    return win;
}
