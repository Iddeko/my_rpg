/*
** EPITECH PROJECT, 2021
** cpoolday06
** File description:
** return 1 si il n'y a que des lettres et 0 sinon
*/

int my_str_isalpha(char const *s)
{
    for (int i = 0 ; s[i] != '\0' ; i++) {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
            return (1);
    }
    return (0);
}
