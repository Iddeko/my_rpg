/*
** EPITECH PROJECT, 2021
** lib
** File description:
** my_substr
*/

#include <stdlib.h>

#include "my.h"

char *my_substr(int first, int last, char const *str)
{
    int sub_len;

    if (last < my_strlen(str))
        sub_len = last - first;
    else
        sub_len = my_strlen(str) - first;

    char *res = malloc(sizeof(char) * (sub_len + 1));

    for (int i = 0; i < sub_len; i++) {
        res[i] = str[i + first];
    }
    res[sub_len] = '\0';
    return (res);
}
