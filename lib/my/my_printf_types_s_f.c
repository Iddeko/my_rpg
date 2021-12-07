/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** types
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#include "printf.h"
#include "my.h"

static void write_the_spaces_2(char *);
static void print_spaces_2(formats, char *);

int write_string_formated(va_list param, formats options)
{
    char *current_str = my_strdup(va_arg(param, char *));
    char backslash[] = "\\";
    char *res;

    if (options.number[0] != '-')
        print_spaces_2(options, current_str);
    for (int i = 0; current_str[i] != '\0'; i++) {
        if (current_str[i] < 32 || current_str[i] >= 127) {
            write(1, &backslash, 1);
            res = my_dec_to_base(current_str[i], "01234567");
            write_the_spaces_2(res);
            write(1, res, my_strlen(res));
        } else {
            write(1, &current_str[i], 1);
        }
    }
    if (options.number[0] == '-')
        print_spaces_2(options, current_str);
    return (1 + my_strlen(options.number));
}

static void print_spaces_2(formats options, char *txt)
{
    int count = 0;
    int nb = ABS(my_getnbr(options.number));
    char spacechar[] = " ";

    for (int i = 0; txt[i] != '\0'; i++) {
        if (txt[i] < 32 || txt[i] >= 127)
            count += 1;
    }
    for (int i = 0; i < nb - (my_strlen(txt) + count * 3); i++)
        write(1, &spacechar, 1);
}

static void write_the_spaces_2(char *res)
{
    char space[] = "0";

    for (int i = my_strlen(res); i < 3; i++)
        write(1, &space, 1);
}
