/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** modifiers
*/

#include "my.h"

formats modify_short(formats options)
{
    if (options.is_short == 1 && options.is_short_short == 0) {
        options.is_short = 0;
        options.is_short_short = 1;
        options.to_return += 1;
    } else if (options.is_short == 0 && options.is_short_short == 0) {
        options.is_short = 1;
        options.to_return += 1;
    } else
        options.to_return = -1;
    return (options);
}

formats modify_long(formats options)
{
    if (options.is_long == 1 && options.is_long_long == 0) {
        options.is_long = 0;
        options.is_long_long = 1;
        options.to_return += 1;
    } else if (options.is_long == 0 && options.is_long_long == 0) {
        options.is_long = 1;
        options.to_return += 1;
    } else
        options.to_return = -1;
    return (options);
}

formats modify_hashtag(formats options)
{
    if (options.is_hasht == 0) {
        options.is_hasht = 1;
    } else
        options.to_return = -1;
    return (options);
}

formats reset_struct(formats option)
{
    for (int i = 0; i < 10; i++)
        option.number[i] = 'a';
    option.number[10] = '\0';
    option.is_long = 0;
    option.is_long_long = 0;
    option.is_short = 0;
    option.is_short_short = 0;
    option.is_hasht = 0;
    option.go_next = 0;
    option.to_return = 0;
    return (option);
}

formats print_elem_formats(int in, char *str, formats options)
{
    switch (str[in]) {
        case 'h':
            options = modify_short(options);
            break;
        case 'l':
            options = modify_long(options);
            break;
        case '-':
            options.number[0] = '-';
            options.to_return += 1;
            break;
        case '#':
            options = modify_hashtag(options);
            break;
        default:
            options.go_next = 1;
    }
    return (options);
}
