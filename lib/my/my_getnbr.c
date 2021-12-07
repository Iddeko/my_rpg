/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** get the numbers from a string
*/

#include "my.h"

static int my_getnbr_2(char const *, int, int, int);

int my_getnbr(char const *str)
{
    int number = 0;
    int count = 0;
    int step = 0;

    for (int i = 0; str[i] != '\0' && my_char_isnum(str[i]) == 0; i ++) {
        if (my_char_isalpha(str[i]) == 1)
            return (0);
        if (str[i] == '-')
            count -= 1;
        if (str[i] == '+')
            count += 1;
        step ++;
    }
    number = my_getnbr_2(str, step, count, number);
    if (count < 0 && count % 2 != 0)
        return (number * -1);
    else
        return (number);
}

static int my_getnbr_2(char const *str, int step, int count, int number)
{
    for (int i = step; str[i] != '\0' && my_char_isnum(str[i]) == 1; i ++) {
        if ((((long) number * 10 + (str[i]) - '0') <= 2147483648 &&
            (count < 0 && count % 2)) ||
            (((long) number * 10 + (str[i]) - '0') <= 2147483647 &&
            !(count < 0 && count % 2))) {
            number *= 10;
            number += str[i] - '0';
        } else
            return (0);
    }
    return (number);
}
