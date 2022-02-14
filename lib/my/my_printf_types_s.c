/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** types
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#include "my.h"

static void print_spaces_3(formats, char *);

int write_string(va_list param, formats options)
{
    char *current_str = my_strdup(va_arg(param, char *));

    if (options.number[0] != '-')
        print_spaces_3(options, current_str);
    write(1, current_str, my_strlen(current_str));
    if (options.number[0] == '-')
        print_spaces_3(options, current_str);
    return (1 + my_strlen(options.number));
}

static void print_spaces_3(formats options, char *txt)
{
    int nb = ABS(my_getnbr(options.number));
    char spacechar[] = " ";

    for (int i = 0; i < nb - my_strlen(txt); i++)
        write(1, &spacechar, 1);
}
