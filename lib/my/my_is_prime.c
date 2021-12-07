/*
** EPITECH PROJECT, 2021
** my_is_prime
** File description:
** retourne 1 si le nombre est premier et 0 si non
*/

static int my_is_prime_square_root(int nb);

int my_is_prime(int nb)
{
    int square_rooted = my_is_prime_square_root(nb);

    if (nb < 2)
        return (0);
    if (nb < 4)
        return (1);
    if (nb % 2 == 0)
        return (0);
    for (int i = square_rooted; i >= 2; i --) {
        if (nb % i == 0)
            return (0);
    }
    return (1);
}

static int my_is_prime_square_root(int nb)
{
    int compteur = 0;

    for (int odd = 1; nb > 0; odd += 2) {
        nb -= odd;
        compteur ++;
    }
    return (compteur);
}
