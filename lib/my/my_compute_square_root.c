/*
** EPITECH PROJECT, 2021
** my_compute_square_root
** File description:
** retourne la racine carré du nombre placé en entré
*/

int my_compute_square_root(int nb)
{
    int compteur = 0;
    int odd = 1;

    while (nb > 0) {
        nb -= odd;
        compteur++;
        odd += 2;
    }
    if (nb < 0)
        return (0);
    return (compteur);
}
