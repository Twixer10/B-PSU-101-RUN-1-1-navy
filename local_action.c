/*
** EPITECH PROJECT, 2020
** LOCAL ACTION
** File description:
** NO DESCRIPTION FOR YOU
*/

#include "./include/navy.h"

void local_attack(int letter, int pos)
{
    int column = where_start(letter + 65);
    int lign = (18 + 18 + (18 * pos));

    if (manager.enemy_map[column + lign] == '.' ) {
        manager.enemy_map[column + lign] = 'o';
        manager.enemy_game_map[column + lign] = 'o';
        my_putchar(letter + 65);
        my_printf("%d: missed\n", (pos + 1));
    } else if (manager.enemy_map[column + lign] != '.' ||
                manager.enemy_map[column + lign] != 'o' ) {
        manager.enemy_map[column + lign] = 'x';
        manager.enemy_game_map[column + lign] = 'x';
        my_putchar(letter + 65);
        my_printf("%d: hit\n", (pos + 1));
    }
}

void local_have_attack(void)
{
    int column = where_start(manager.attack_letter + 65);
    int lign = (18 + 18 + (18 * manager.attack_position));

    if (manager.map[column + lign] == '.' ) {
        manager.map[column + lign] = 'o';
        my_putchar(manager.attack_letter + 65);
        my_printf("%d: missed\n", (manager.attack_position + 1));
    } else if (manager.map[column + lign] != '.' ||
                manager.map[column + lign] != 'o' ) {
        manager.map[column + lign] = 'x';
        my_putchar(manager.attack_letter + 65);
        my_printf("%d: hit\n", (manager.attack_position + 1));
    }
    manager.attack_position = 0;
    manager.attack_letter = 0;
    manager.message_entry = 0;
}

void check_win(void)
{
    int me = manager.nbr_boat;
    int ennemy = manager.nbr_boat;

    for (int i = 0; manager.map[i] != '\0'; i++) {
        ((manager.map[i] == 'x')?ennemy--:0);
        ((manager.enemy_map[i] == 'x')?me--:0);
    }
    if (me == 0 && ennemy != 0) {
        manager.rtn_value = 0;
        my_putstr("\nI won\n");
    } else if (me != 0 && ennemy == 0) {
        manager.rtn_value = 1;
        my_putstr("\nEnemy won\n");
    }
}

void relunch(void)
{
    int me = manager.nbr_boat;
    int ennemy = manager.nbr_boat;

    for (int i = 0; manager.map[i] != '\0'; i++) {
        ((manager.map[i] == 'x')?ennemy--:0);
        ((manager.enemy_map[i] == 'x')?me--:0);
    }
    if (me != 0 && ennemy != 0) {
        init_game();
    }
}