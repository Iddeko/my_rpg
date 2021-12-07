/*
** EPITECH PROJECT, 2021
** my_computer_power_rec
** File description:
** Retourne la puissance de n par p de manière recursive
*/

int my_compute_power(int nb, int p)
{
    if (p >= 2)
        return (nb * my_compute_power(nb, p - 1));
    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    if (p == 1)
        return (nb);
}
