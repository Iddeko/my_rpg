/*
** EPITECH PROJECT, 2021
** cpoolday06
** File description:
** Copies n char from a str to an other
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    for (i = 0; i != n && src[i] != '\0' && dest[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
