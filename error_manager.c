/*
** EPITECH PROJECT, 2020
** ERROR MANAGER
** File description:
** MANAGE ERROR
*/

#include "./include/navy.h"

int incorrect_argument(void)
{
    my_putstr("./navy: incorrect argument\nTry './navy -h' for more");
    my_putstr("information.");
    return (84);
}

int help_message(void)
{
    my_putstr("USAGE\n\t./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n\tfirst_player_pid: only for the 2nd player.");
    my_putstr("pid of the first player.\n\tnavy_positions: file representing ");
    my_putstr("the positions of the ships.\n");
    return (0);
}