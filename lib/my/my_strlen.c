/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** retourne la taille d'un str
*/

#include <stdlib.h>

int my_strlen(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}
