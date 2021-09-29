/*
** EPITECH PROJECT, 2020
** SIGNAL MESSAGE
** File description:
** MANAGE SIGNAL MESSAGE
*/

#include "./include/navy.h"

void send_sig_message(int pid, int letter, int position)
{
    for (int i = 0; i != 16; i++) {
        if (i <= 7) {
            kill(pid, (letter == i?SIGUSR1:SIGUSR2));
        }
        if (i > 7) {
            kill(pid, (position == (i-8)?SIGUSR1:SIGUSR2));
        }
        usleep(0.1);
    }
}

void get_sig_message(int sig)
{
    if (manager.message_entry <= 7){
        if (sig == SIGUSR1) {
            manager.attack_letter = manager.message_entry;
        }
    }
    if (manager.message_entry > 7){
        if (sig == SIGUSR1) {
            manager.attack_position = (manager.message_entry - 8);
        }
    }
    if (manager.message_entry == 15) {
        manager.receive_data = FALSE;
    }
    manager.message_entry++;
}