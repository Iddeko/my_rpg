/*
** EPITECH PROJECT, 2021
** lib
** File description:
** duplicate a str
*/

#include <stdlib.h>

#include "my.h"

char *my_strdup(char const *src)
{
    int i;
    char *str = malloc(sizeof(char) * (my_strlen(src) + 1));

    for (i = 0; src[i] != '\0'; i++)
        str[i] = src[i];
    str[i] = '\0';
    return (str);
}
