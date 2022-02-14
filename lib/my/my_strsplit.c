/*
** EPITECH PROJECT, 2021
** my_strsplit
** File description:
** split an str in an array of str separted by selected char
*/

#include <stdlib.h>
#include <stdio.h>

#include "my.h"

int number_of_lines(char *str, char charac)
{
    int count = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == charac)
            count += 1;
    }
    return (count);
}

int end_check(int *i, int nb, char *str)
{
    for (; (*i) != nb + 1; (*i)++)
        if (str[(*i)] == '\0')
            return (1);
    return (0);
}

char **my_strsplit(char *str, char charac)
{
    int nb = 0;
    int line = 0;
    int nb_line = number_of_lines(str, charac);
    char **array = malloc(sizeof(char *) * (nb_line + 1));

    for (int i = 0; str[i] != '\0';) {
        for (nb = i; str[nb] != '\0' && str[nb] != charac; nb++);
        array[line] = my_strdup(my_substr(i, nb, str));
        line += 1;
        if (end_check(&i, nb, str) == 1)
            break;
    }
    array[nb_line] = NULL;
    return (array);
}
