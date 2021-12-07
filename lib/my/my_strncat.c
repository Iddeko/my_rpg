/*
** EPITECH PROJECT, 2021
** cpoolday7
** File description:
** concenate the n of the src to the dest
*/

#include "my.h"

char *my_strncat(char *dest , char const *src, int nb)
{
    int len = my_strlen(dest);

    for (int i = 0; src[i] != '\0' && i < nb; i ++)
        dest[len + i] = src[i];
    dest[len + nb] = '\0';
    return (dest);
}
