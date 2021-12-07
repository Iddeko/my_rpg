/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** decimal base to an other base
*/

#include <stdlib.h>

#include "my.h"

char *my_dec_to_base_unsigned(unsigned long long nb, char *base)
{
    unsigned long long nb2 = nb;
    int i = 0;

    if (nb == 0)
        return ("0");
    for (i = 0; nb2 >= 1; i++)
        nb2 = nb2 / my_strlen(base);
    char *result = malloc(sizeof(char *) * (i + 1));

    for (i = 0; nb >= 1; i++) {
        result[i] = base[nb % my_strlen(base)];
        nb = nb / my_strlen(base);
    }
    result[i] = '\0';
    return (my_revstr(result));
}
