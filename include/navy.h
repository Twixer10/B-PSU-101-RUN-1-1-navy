/*
** EPITECH PROJECT, 2020
** B-PSU-101-RUN-1-1-navy-thomas.techer
** File description:
** navy
*/

#ifndef NAVY_H_
#define NAVY_H_

#include "../include/my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <signal.h>

enum user_t {
    USER1,
    USER2
};

typedef struct manager_h {
    char *map;
    char *enemy_map;
    char *enemy_game_map;
    int my_pid;
    int enemy_pid;
    int in_game;
    int user;
    int message_entry;
    int attack_letter;
    int attack_position;
    my_bool receive_data;
    int who_play;
    int nbr_boat;
    int rtn_value;
} manager_t;

extern manager_t manager;

int incorrect_argument(void);
int help_message(void);
void try_init_player_one(char *path);
void try_init_player_two(char *path);
char *load_map(char *path);
int where_start(char c);
char *add_to_map(char *map, char *line);
void init_empty_map(char *map);
void init_player_one(int pid);
void init_player_two(int pid, int enemy_pid);
void store_pid(char *path, int pid);
int get_pid(char *path);
void store_in_file(char *path, char *str);
char *get_from_file(char *path);
void disp_maps();
char *get_message(int i);
void init_game();
void get_sig_message(int sig);
void send_sig_message(int pid, int letter, int position);
void init_attack();
void init_wait_attack();
void init_attack2();
void init_wait_attack2();
void local_attack(int letter, int pos);
my_bool try_sig_send(char *str);
void local_have_attack();
void check_win();
void relunch();


#endif /* !NAVY_H_ */