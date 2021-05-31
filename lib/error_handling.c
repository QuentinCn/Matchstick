/*
** EPITECH PROJECT, 2021
** error_handling.c
** File description:
** handle matchstick errors
*/

#include <stdbool.h>

int my_getnbr(char const *nb);

bool handle_error(int ac, char const * const av[])
{
    if (ac != 3)
        return false;
    for (int i = 1; av[i]; i += 1)
        for (int j = 0; av[i][j] != '\0'; j += 1)
            if (av[i][j] > '9' || av[i][j] < '0')
                return false;
    if (!(my_getnbr(av[1]) > 1 && my_getnbr(av[1]) < 100))
        return false;
    if (my_getnbr(av[2]) <= 0)
        return false;
    return true;
}
