/*
** EPITECH PROJECT, 2020
** INIT PLAYERS
** File description:
** NO DESCRIPTION FOR YOU
*/

#include "./include/navy.h"

void handler(int sig)
{
    if (sig == SIGUSR1 || sig == SIGUSR2){

    }
}

void init_player_one(int pid)
{
    manager.my_pid = pid;
    signal(SIGUSR1, handler);
    my_printf("my_pid: %d\nwaiting for enemy connection...", pid);
    pause();
    manager.enemy_pid = get_pid("tmp/pid_user2");
    manager.enemy_map = get_from_file("tmp/map_user2");
    my_putstr("\nenemy connected\n");
}

void init_player_two(int pid, int enemy_pid)
{
    manager.who_play++;
    manager.my_pid = pid;
    manager.enemy_pid = enemy_pid;
    signal(SIGUSR1, handler);
    my_printf("my_pid: %d\n", pid);
    store_pid("tmp/pid_user2", pid);
    manager.enemy_map = get_from_file("tmp/map_user1");
    kill(enemy_pid, SIGUSR1);
    my_putstr("successfully connected\n");
}