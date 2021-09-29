/*
** EPITECH PROJECT, 2020
** NAVY MAIN
** File description:
** NO DESCRIPTION FOUND
*/

#include "./include/navy.h"

manager_t manager;

int main(int ac, char **av)
{
    if (ac == 1 || ac > 3)
        return (incorrect_argument());
    if (check_args(av, 1, "-h") && !av[2])
        return (help_message());
    if (ac == 2 && av[1]) {
        try_init_player_one(av[1]);
        init_player_one(getpid());
    }
    if (ac == 3 && av[2]) {
        try_init_player_two(av[2]);
        init_player_two(getpid(), my_getnbr(av[1]));
    }
    manager.rtn_value = 18;
    init_game(ac);
    return (manager.rtn_value);
}
