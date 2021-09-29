/*
** EPITECH PROJECT, 2020
** MAP MANAGER
** File description:
** MANAGE MAP FOR THE BATTLE
*/

#include "./include/navy.h"

char *load_map(char *path)
{
    char *map = malloc(sizeof(char) * 181);
    init_empty_map(map);
    int file = open(path, O_RDONLY);
    char *line = malloc(sizeof(char) * 8);
    int i = 0;

    if (file < 0) {
        my_putstr("Error, this map can not be loaded");
    }
    while (i < 4) {
        read(file, line, 8);
        map = add_to_map(map, line);
        i = i + 1;
    }
    close(file);
    return (map);
}

char *add_to_map(char *map, char *line)
{
    int ln = (line[3] - '0') + 1;
    int start = (ln * 18 + where_start(line[2]));
    int to_print = (line[0] - '0');
    int i;

    if (line[2] == line[5]) {
        for (i = 1; i <= to_print; i++) {
            map[start] = line[0];
            start = start + 18;
            manager.nbr_boat++;
        }
    } else if (line[3] == line[6]) {
        for (i = 1; i <= to_print; i++) {
            map[start] = line[0];
            start = start + 2;
            manager.nbr_boat++;
        }
    }
    return (map);
}

void init_empty_map(char *map)
{
    int fd = open("./maps/map", O_RDONLY);

    read(fd, map, 180);
    fd = close(fd);
}