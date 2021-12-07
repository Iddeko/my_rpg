/*
** EPITECH PROJECT, 2021
** my_char_isalpha
** File description:
** return 1 if char is alphabetic
*/

int my_char_isalpha(char const chr)
{
    if ((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z'))
        return (1);
    return (0);
}
