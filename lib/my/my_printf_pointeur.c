/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** types_unsigned
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#include "my.h"

int write_pointeur(va_list param, formats options, char *base)
{
    void *current_int = va_arg(param, void *);
    char *str = my_dec_to_base_long((long) current_int, base);

    print_spaces(options, str);
    write(1, "0x", 2);
    write(1, str, my_strlen(str));
    print_spaces_minus(options, str);
    return (1 +my_strlen(options.number));
}
