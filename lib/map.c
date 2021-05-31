/*
** EPITECH PROJECT, 2021
** map.c
** File description:
** manage the map
*/

#include <stddef.h>
#include <stdlib.h>

void my_putstr(char const *str);

static char *complete_line_with_star(char *str, int len)
{
    for (int i = 0; i < len; i += 1) {
        str[i] = '*';
        str[i + 1] = '\0';
    }
    return str;
}

static char *create_line(char *str, int i, int len)
{
    int j = 0;
    int nb_pipe = 1 + (i - 1) * 2;

    for (; j < len; j += 1) {
        if (j == 0 || j == len - 1)
            str[j] = '*';
        else if (j > (len - 1) / 2 - i && j < (len - 1) / 2 + nb_pipe / 2 + 1)
            str[j] = '|';
        else
            str[j] = ' ';
        str[j + 1] = '\0';
    }
    return str;
}

char **create_map(int nb_line)
{
    char **map = malloc(sizeof(char *) * (nb_line + 3));

    for (int i = 0; i < nb_line + 2; i += 1) {
        map[i] = malloc(nb_line * 2 + 2);
        if (i == 0 || i == nb_line + 1)
            map[i] = complete_line_with_star(map[i], nb_line * 2 + 1);
        else
            map[i] = create_line(map[i], i, nb_line * 2 + 1);
        map[i + 1] = NULL;
    }
    return map;
}

void display_map(char **map)
{
    for (int i = 0; map[i]; i += 1) {
        my_putstr(map[i]);
        my_putstr("\n");
    }
}
