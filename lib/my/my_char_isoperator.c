/*
** EPITECH PROJECT, 2021
** my_str_isoperator
** File description:
** return 1 if the char is an operator else return 0
*/

int my_char_isoperator(char const chr)
{
    if (chr == '-' || chr == '+' || chr == '/' || chr == '*')
        return (1);
    return (0);
}
