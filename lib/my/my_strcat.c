/*
** EPITECH PROJECT, 2021
** cpoolday7
** File description:
** concatenates two string
*/

#include "my.h"

int my_strlen(char const *str);

void my_strcat(char **dest, char const *src)
{
    int len = my_strlen(*dest);
    int i;

    for (i = 0; src[i] != '\0'; i++)
        (*dest)[len + i] = src[i];
    (*dest)[len + i] = '\0';
}
