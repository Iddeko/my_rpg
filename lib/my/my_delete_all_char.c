/*
** EPITECH PROJECT, 2022
** lib
** File description:
** delete_all_char
*/

#include <stdlib.h>

char *delete_all_char(char *line, char charac)
{
    int new_size = 0;
    int j = 0;
    char *new_line;

    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] != charac)
            new_size += 1;
    new_line = malloc(sizeof(char) * (new_size + 1));
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] != charac) {
            new_line[j] = line[i];
            j++;
        }
    }
    new_line[j] = '\0';
    return (new_line);
}
