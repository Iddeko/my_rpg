/*
** EPITECH PROJECT, 2021
** my_char_isnum
** File description:
** if char is num return 1
*/

int my_char_isnum(char const chr)
{
    if (chr >= '0' && chr <= '9')
        return (1);
    return (0);
}
