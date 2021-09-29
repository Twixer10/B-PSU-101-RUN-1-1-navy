/*
** EPITECH PROJECT, 2020
** INIT GAME
** File description:
** NO DESCRIPTION FOUND
*/

#include "./include/navy.h"
#include "./include/my.h"

void disp_maps(void)
{
    my_printf("\nmy positions:\n%s\nenemy's positions:\n%s\n", manager.map,
    manager.enemy_game_map);
}

my_bool try_sig_send(char *str)
{
    if (my_strlen(str) != 3) {
        my_putstr("wrong position\nattack: ");
        return (FALSE);
    }
    if (str[0] >= 'A' && str[0] <= 'H') {
        if (str[1] >= '1' && str[1] <= '8') {
            local_attack(str[0] - 65, str[1] - 49);
            send_sig_message(manager.enemy_pid, str[0] - 65, str[1] - 49);
            return (TRUE);
        } else
            my_putstr("wrong position\nattack: ");
    } else
        my_putstr("wrong position\nattack: ");
    return (FALSE);
}

void init_attack(void)
{
    size_t t = 0;
    char *line = NULL;
    my_bool rtn = FALSE;

    my_putstr("attack: ");
    while (getline(&line, &t, stdin)){
        rtn = try_sig_send(line);
        if (rtn)
            break;
    }
    check_win();
    if (manager.rtn_value != 18)
        return;
    else
        init_wait_attack2();
}

void init_wait_attack(void)
{
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
        init_attack2();
}

void init_game(void)
{
    manager.who_play++;
    disp_maps();
    if (manager.who_play % 2) {
        init_attack();
    } else {
        init_wait_attack();
    }
    if (manager.rtn_value != 18)
        return;
}