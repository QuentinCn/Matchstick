/*
** EPITECH PROJECT, 2021
** turn.c
** File description:
** manage each turn
*/

#include "my.h"
#include <stddef.h>
#include <stdlib.h>

static char **delete_in_map(char **map, int line, int nb_stick, int player)
{
    int i = my_strlen(map[line]) - 1;

    for (; map[line][i] != '|' && i > 0; i -= 1);
    for (int j = i; i - j != nb_stick; j -= 1)
        map[line][j] = ' ';
    if (player == 1)
        my_putstr("Player removed ");
    if (player == 2)
        my_putstr("AI removed ");
    my_put_nbr(nb_stick);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putstr("\n");
    return map;
}

char **do_player_turn(char **map, int nb_line, int max_stick, int *nb_stick)
{
    int line = 0;

    if (*nb_stick != -2) {
        display_map(map);
        my_putstr("\nYour turn:\n");
    }
    line = get_info("Line: ", nb_line);
    if (line == -1) {
        free_double_char(map);
        return NULL;
    }
    *nb_stick = get_info("Matches: ", max_stick);
    if (*nb_stick == -1) {
        free_double_char(map);
        return NULL;
    }
    *nb_stick = check_in_map(map, line, *nb_stick);
    if (*nb_stick > 0)
        map = delete_in_map(map, line, *nb_stick, 1);
    return map;
}

static int get_best_line(char **map, int nb_stick)
{
    int line_stick = 0;

    for (int i = 0; map[i]; i += 1) {
        line_stick = 0;
        for (int j = 0; map[i][j] != '\0'; j += 1)
            if (map[i][j] == '|')
                line_stick += 1;
        if (line_stick >= nb_stick)
            return i;
    }
    return -1;
}

static int *find_ai_pos(char **map, int nb_line, int max_stick, int turn)
{
    int *pos = malloc(sizeof(int) * (2));
    int nb_stick = 0;
    int nb_max_stick = nb_line * nb_line;
    int k = 0;

    pos[0] = -1;
    pos[1] = max_stick + 1;
    for (int i = 0; map[i]; i += 1)
        for (int j = 0; map[i][j] != '\0'; j += 1)
            if (map[i][j] == '|')
                nb_stick += 1;
    for (; k < nb_max_stick; k += (nb_max_stick - nb_stick) / turn);
    k -= (nb_max_stick - nb_stick) / turn;
    pos[1] = nb_max_stick - k;
    for (; pos[1] >= max_stick; pos[1] -= 1);
    for (; pos[1] > 0; pos[1] -= 1) {
        pos[0] = get_best_line(map, pos[1]);
        if (pos[0] != -1)
            return pos;
    }
    free_double_char(map);
    return NULL;
}

char **do_ai_turn(char **map, int nb_line, int max_stick, int turn)
{
    int *pos = find_ai_pos(map, nb_line, max_stick, turn);

    display_map(map);
    my_putstr("\nAI's turn...\n");
    map = delete_in_map(map, pos[0], pos[1], 2);
    free(pos);
    return map;
}
