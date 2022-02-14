/*
** EPITECH PROJECT, 2022
** lib
** File description:
** rename_all_char
*/

#include <stdlib.h>
#include "my.h"

char *rename_all_char(char *line, char charac, char charac2)
{
    int i = 0;
    char *new_line;

    new_line = malloc(sizeof(char) * (my_strlen(line) + 1));
    for (i = 0; line[i] != '\0'; i++) {
        if (line[i] != charac)
            new_line[i] = line[i];
        else
            new_line[i] = charac2;
    }
    new_line[i] = '\0';
    return (new_line);
}
