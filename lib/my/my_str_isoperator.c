/*
** EPITECH PROJECT, 2021
** my_str_isoperator
** File description:
** return 1 if the str is an operator else return 0
*/

int my_str_isoperator(char const *str)
{
    for (int i = 0 ; str[i] != '\0' ; i ++) {
        if (str[i] == '-' || str[i] == '+' || str[i] == '/' || str[i] == '*')
            return (1);
    }
    return (0);
}
