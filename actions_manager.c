/*
** EPITECH PROJECT, 2020
** ACTION MANAGER
** File description:
** NO DESCRIPTION FOUND
*/

#include "./include/navy.h"
#include "./include/my.h"

char *get_message(int i)
{
    char *s = malloc(sizeof(char) * (3));
    int k = read(i, s, 3);
    k = k;
    return (s);
}