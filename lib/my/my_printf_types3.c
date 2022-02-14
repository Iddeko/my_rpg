/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** types3
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#include "my.h"

static void print_spaces_c(formats);

int write_char(va_list param, formats options)
{
    char current_char = va_arg(param, int);
    if (options.number[0] != '-')
        print_spaces_c(options);
    write(1, &current_char, 1);
    if (options.number[0] == '-')
        print_spaces_c(options);
    return (1);
}

static void print_spaces_c(formats options)
{
    int nb = ABS(my_getnbr(options.number));
    char spacechar[] = " ";

    for (int i = 0; i < nb - 1; i++)
        write(1, &spacechar, 1);
}

int write_char_none(int ret)
{
    char current_char = '%';

    write(1, &current_char, 1);
    return (ret);
}
