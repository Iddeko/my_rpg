/*
** EPITECH PROJECT, 2021
** cpoolday06
** File description:
** write every first letters of a word in capital letters
*/

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i ++) {
        if ('a' < str[i] && str[i] < 'z')
            str[i] -= 32;
    }
    return (str);
}
