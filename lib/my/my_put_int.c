/*
** EPITECH PROJECT, 2021
** my_put_int
** File description:
** display the given number
*/

#include <unistd.h>

void my_put_int(int nb)
{
    char cha[1];

    if (nb <= 9 && nb != -2147483648) {
        if (nb < 0) {
            write(1,"-",1);
            my_put_int(nb * -1);
        } else {
            cha[0] = nb + '0';
            write(1, cha, 1);
        }
    } else if (nb != -2147483648) {
        my_put_int(nb / 10);
        my_put_int(nb % 10);
    } else
        write(1, "-2147483648", 11);
}
