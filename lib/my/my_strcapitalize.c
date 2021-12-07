/*
** EPITECH PROJECT, 2021
** my_strcapitalize
** File description:
** put a capital in front of all the words
*/

void my_strcapitalize_second(char *str, int i);

char *my_strcapitalize(char *str)
{
    if ('a' < str[0] && str[0] < 'z')
        str[0] -= 32;
    for (int i = 1 ; str[i] != '\0' ; i ++) {
        if ('A' < str[i] && str[i] < 'Z')
            str[i] += 32;
        if ('a' < str[i] && str[i] < 'z')
            my_strcapitalize_second(str,i);
    }
    return (str);
}

void my_strcapitalize_second(char *str, int i)
{
    if (str[i - 1] > 'z' || str[i - 1] < 'a') {
        if (str[i - 1] > 'Z' || str[i - 1] < 'A')
            str[i] -= 32;
    }
}
