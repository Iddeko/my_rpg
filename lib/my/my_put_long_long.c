/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** display the given number
*/

#include <unistd.h>

void my_put_long_long(long long nb)
{
    char cha[1];

    if (nb <= 9 && nb != -9223372036854775807) {
        if (nb < 0) {
            write(1, "-", 1);
            my_put_long_long(nb * -1);
        } else {
            cha[0] = nb + '0';
            write(1, cha, 1);
        }
    } else if (nb != -9223372036854775807) {
        my_put_long_long(nb / 10);
        my_put_long_long(nb % 10);
    } else
        write(1, "-9223372036854775807", 20);
}
