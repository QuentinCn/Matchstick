/*
** EPITECH PROJECT, 2021
** gameplay.c
** File description:
** manage the gameplay
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

void free_double_char(char **map)
{
    for (int i = 0; map[i]; i += 1)
        free(map[i]);
    free(map);
}

static bool is_there_a_win(char **map)
{
    for (int i = 0; map[i]; i += 1)
        for (int j = 0; map[i][j] != '\0'; j += 1)
            if (map[i][j] == '|')
                return false;
    return true;
}

int get_info(char *str, int max)
{
    size_t size = 0;
    char *nb = NULL;

    my_putstr(str);
    if (getline(&nb, &size, stdin) < 0)
        return -1;
    return check_nb(nb, str, max);
}

int play(char **map, int nb_line, int max_stick)
{
    int turn = 0;
    int nb_stick = 0;

    for (; !is_there_a_win(map); ++turn) {
        if (turn % 2 == 0) {
            map = do_player_turn(map, nb_line, max_stick, &nb_stick);
            if (nb_stick == -2)
                turn -= 1;
            if (map == NULL)
                return 0;
        } else
            map = do_ai_turn(map, nb_line, max_stick, turn);
    }
    display_map(map);
    free_double_char(map);
    return (turn % 2 == 0)? 1: 2;
}
