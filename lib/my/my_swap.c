/*
** EPITECH PROJECT, 2021
** my_swap
** File description:
** echange la valeur de deux int
*/

void my_swap(int *a, int *b)
{
    int temporary = *a;

    *a = *b;
    *b = temporary;
}
