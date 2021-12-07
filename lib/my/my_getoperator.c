/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** get the operator from a string or -1 if there is none
*/

char my_getoperator(char const *str)
{
    for (int i = 0; str[i] != '\0' ; i ++) {
        if (str[i] == '/')
            return ('/');
        if (str[i] == '*')
            return ('*');
        if (str[i] == '+')
            return ('+');
        if (str[i] == '-')
            return ('-');
    }
    return(-1);
}
