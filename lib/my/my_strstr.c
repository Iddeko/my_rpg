/*
** EPITECH PROJECT, 2021
** cpoolday06
** File description:
** revoie un pointeur vers un point defini d'un char
*/

#include <stddef.h>

char *my_strstr(char *str, char const *to_find)
{
    int len = 0;
    int consecutive = 0;

    for (int i = 0; to_find[i] != '\0'; i ++)
        len ++;
    for (int i = 0; str[i] != '\0'; i ++) {
        if (str[i] == to_find[consecutive] && consecutive != len)
            consecutive ++;
        else if (str[i] != to_find[i] && consecutive != len)
            consecutive = 0;
        else
            return (&str[i - len]);
    }
    return (NULL);
}
