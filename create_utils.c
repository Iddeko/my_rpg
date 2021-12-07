/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** creat_utils
*/

#include "my_rpg.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *res = malloc(sizeof(framebuffer_t));

    res->height = height;
    res->width = width;
    res->pixels = malloc(sizeof(unsigned char) * width * height * 32 / 8);
    return (res);
}

sfRenderWindow *create_window(unsigned int width, unsigned int height)
{
    sfVideoMode mode = {width, height, 32};
    return (sfRenderWindow_create(mode, "My screen", sfDefaultStyle, NULL));
}
