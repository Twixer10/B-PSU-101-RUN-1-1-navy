/*
** EPITECH PROJECT, 2020
** WHERE START
** File description:
** NO DESCRIPTION FOUND
*/

#include "./include/navy.h"

int where_start2(int i, char c)
{
    switch (c) {
    case 'E':
        i = 10;
        break;
    case 'F':
        i = 12;
        break;
    case 'G':
        i = 14;
        break;
    case 'H':
        i = 16;
        break;
    }
    return (i);
}

int where_start(char c)
{
    int i = 0;

    switch (c) {
    case 'A':
        i = 2;
        break;
    case 'B':
        i = 4;
        break;
    case 'C':
        i = 6;
        break;
    case 'D':
        i = 8;
        break;
    }
    return (where_start2(i, c));
}