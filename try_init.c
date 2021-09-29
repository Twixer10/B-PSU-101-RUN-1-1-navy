/*
** EPITECH PROJECT, 2020
** TRY INIT MANAGER
** File description:
** Try to init players
*/

#include "./include/navy.h"

void try_init_player_one(char *path)
{
    manager.enemy_game_map = malloc(sizeof(char) * 181);
    manager.map = load_map(path);
    store_in_file("tmp/map_user1", manager.map);
    init_empty_map(manager.enemy_game_map);
    manager.user = USER1;
}

void try_init_player_two(char *path)
{
    manager.enemy_game_map = malloc(sizeof(char) * 181);
    manager.map = load_map(path);
    store_in_file("tmp/map_user2", manager.map);
    init_empty_map(manager.enemy_game_map);
    manager.user = USER2;
}