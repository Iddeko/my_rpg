/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** utils
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#include "my.h"

void print_spaces(formats options, char *str)
{
    char spacechar[] = " ";
    char zerochar[] = "0";
    int j = options.is_hasht * 2;

    for (int i = 0; i < my_getnbr(options.number) - my_strlen(str) - j; i++) {
        if (options.number[0] != '0')
            write(1, &spacechar, 1);
        else
            write(1, &zerochar, 1);
    }
}

void print_spaces_minus(formats options, char *str)
{
    char spacechar[] = " ";
    int j = my_strlen(str);

    if (options.number[0] == '-') {
        for (int i = 0; i < my_getnbr(options.number) * -1 - j; i++) {
            write(1, &spacechar, 1);
        }
    }
}

int long_or_normal(formats options, int len_nb)
{
    if (options.is_long == 1)
        return (len_nb + 2);
    return (len_nb + 3);
}

int short_or_normal(formats options, int len_nb)
{
    if (options.is_short == 1)
        return (len_nb + 2);
    if (options.is_short_short == 1)
        return (len_nb + 3);
    return (len_nb + 1);
}
