/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** types_binary
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#include "printf.h"
#include "my.h"

static int write_binary_long(va_list, formats, char *);

int write_binary(va_list param, formats options, char *base)
{
    if (options.is_long_long == 0 && options.is_long == 0) {
        int current_int = va_arg(param, int);
        char *str = my_dec_to_base(current_int, base);

        print_spaces(options, str);
        if (options.is_hasht == 1) {
            write(1, "0b",2);
            write(1, str, my_strlen(str));
            print_spaces_minus(options, str);
            return (short_or_normal(options, my_strlen(options.number) + 1));
        } else {
            write(1, str, my_strlen(str));
            print_spaces_minus(options, str);
            return (short_or_normal(options, my_strlen(options.number)));
        }
    }
    return (write_binary_long(param, options, base));
}

static int write_binary_long(va_list param, formats options, char *base)
{
    long long current_int = va_arg(param, long long);
    char *str = my_dec_to_base_long(current_int, base);

    print_spaces(options, str);
    if (options.is_hasht == 1) {
        write(1, "0b",2);
        write(1, str, my_strlen(str));
        print_spaces_minus(options, str);
        return (long_or_normal(options, my_strlen(options.number) + 1));
    } else {
        write(1, str, my_strlen(str));
        print_spaces_minus(options, str);
        return (long_or_normal(options, my_strlen(options.number)));
    }
}
