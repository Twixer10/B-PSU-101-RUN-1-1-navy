/*
** EPITECH PROJECT, 2020
** INIT GAME2
** File description:
** NDFFY
*/

#include "./include/navy.h"

void init_attack2(void)
{
    size_t t = 0;
    char *line = NULL;
    my_bool rtn = FALSE;

    manager.who_play++;
    my_putstr("\nattack: ");
    while (getline(&line, &t, stdin)){
        rtn = try_sig_send(line);
        if (rtn)
            break;
    }
    check_win();
    if (manager.rtn_value != 18)
        return;
    else
        relunch();
}

void init_wait_attack2(void)
{
    manager.who_play++;
    my_putstr("\nwaiting for enemy's attack...\n");
    manager.receive_data = TRUE;
    while (manager.receive_data) {
        signal(SIGUSR1, get_sig_message);
        signal(SIGUSR2, get_sig_message);
    }
    local_have_attack();
    check_win();
    if (manager.rtn_value != 18)
        return;
    else
        relunch();
}