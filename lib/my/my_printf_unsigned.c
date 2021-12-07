/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** types_unsigned
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#include "printf.h"
#include "my.h"

static int write_unsigned_long(va_list, formats, char *);

int write_unsigned(va_list param, formats options, char *base)
{
    if (options.is_long_long == 0 && options.is_long == 0) {
        unsigned int current_int = va_arg(param, unsigned int);
        char *str = my_dec_to_base_unsigned(current_int, base);

        print_spaces(options, str);
        write(1, str, my_strlen(str));
        print_spaces_minus(options, str);
        return (short_or_normal(options, my_strlen(options.number)));
    }
    return (write_unsigned_long(param, options, base));
}

static int write_unsigned_long(va_list param, formats options, char *base)
{
    unsigned long long current_int = va_arg(param, unsigned long long);
    char *str = my_dec_to_base_unsigned(current_int, base);

    print_spaces(options, str);
    write(1, str, my_strlen(str));
    print_spaces_minus(options, str);
    return (long_or_normal(options, my_strlen(options.number)));
}
