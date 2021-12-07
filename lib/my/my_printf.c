/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** main
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

#include "printf.h"
#include "my.h"

int my_printf(char *s, ...)
{
    va_list param;
    formats options = {
        .is_long_long = 0,
        .is_long = 0,
        .is_short = 0,
        .is_short_short = 0,
        .is_hasht = 0,
        .go_next = 0,
        .to_return = 0
    };

    va_start(param, s);
    for (int i = 0; s[i] != '\0'; i++) {
        i = process_char(s, i, param, options);
        if (i < 0)
            return (84);
    }
    va_end(param);
    return (0);
}

int process_char(char *s, int i, va_list param, formats options)
{
    if (s[i] == '%') {
        reset_struct(options);
        int len = print_elem_numbers(i + 1, s, param, options);

        if (len < 0)
            return (-1);
        i += len;
    } else
        write(1, &s[i], 1);
    return (i);
}

int print_elem_numbers(int in, char *str, va_list param, formats options)
{
    if (str[in] >= 48 && str[in] <= 57 ) {
        options.number[options.to_return] = str[in];
        options.to_return += 1;
    } else {
        options = print_elem_formats(in, str, options);
        if (options.go_next == 1)
            return (print_elem_flags_1(in, str, param, options));
    }
    return (print_elem_numbers(in + 1, str, param, options));
}

int print_elem_flags_1(int in, char *str, va_list param, formats options)
{
    switch (str[in]) {
        case 's':
            return (write_string(param, options));
        case 'S':
            return (write_string_formated(param, options));
        case 'i':
        case 'd':
            return (write_int(param, options, "0123456789"));
        case 'p':
            return (write_pointeur(param, options, "0123456789abcdef"));
        case 'u':
            return (write_unsigned(param, options, "0123456789"));
        default:
            return (print_elem_flags_2(in, str, param, options));
    }
}

int print_elem_flags_2(int in, char *str, va_list param, formats options)
{
    switch (str[in]) {
        case 'x':
            return (write_hex(param, options, "0123456789abcdef"));
        case 'X':
            return (write_hex_2(param, options, "0123456789ABCDEF"));
        case 'o':
            return (write_octal(param, options, "01234567"));
        case 'b':
            return (write_binary(param, options, "01"));
        case 'c':
            return (write_char(param, options) + options.to_return);
        case '%':
            return (write_char_none(1));
        default:
            return (write_char_none(0));
    }
}
