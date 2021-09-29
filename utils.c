/*
** EPITECH PROJECT, 2020
** UTILS
** File description:
** NO DESCRIPTION FOUND
*/

#include "./include/navy.h"
#include "./include/my.h"

void store_pid(char *path, int pid)
{
    int fd = open(path, O_WRONLY);

    write(fd, my_itoa(pid), my_nbrlen(pid));
    fd = close(fd);
}

int get_pid(char *path)
{
    char tmp[10];
    int fd = open(path, O_RDONLY);

    read(fd, tmp, 10);
    fd = close(fd);
    return (my_getnbr(tmp));
}

void store_in_file(char *path, char *str)
{
    int fd = open(path, O_WRONLY);

    write(fd, str, my_strlen(str));
    fd = close(fd);
}

char *get_from_file(char *path)
{
    char *tmp = malloc(sizeof(char) * 180);
    int fd = open(path, O_RDONLY);

    read(fd, tmp, 180);
    fd = close(fd);
    return (tmp);
}