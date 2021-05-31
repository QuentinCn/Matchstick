/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** .h of matchstick
*/

#ifndef MY
#define MY

#include <stdbool.h>

bool handle_error(int ac, char const * const av[]);
char **create_map(int nb_line);
int my_getnbr(char const *nb);
void my_putstr(char const *str);
void display_map(char **map);
int play(char **map, int nb_line, int max_stick);
void my_put_nbr(int nb);
int check_nb(char *nb, char *str, int max);
int get_info(char *str, int max);
int check_in_map(char **map, int line, int nb_stick);
int my_strlen(char const *str);
char **do_player_turn(char **map, int nb_line, int max_stick, int *stick);
char **do_ai_turn(char **map, int nb_line, int max_stick, int turn);
void free_double_char(char **map);

#endif /* !MY */
