/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** my_arrlen
*/

#include "unistd.h"

int my_arrlen(char **str)
{
    int i;

    for (i = 0; str[i] != NULL; i++);
    return (i);
}
