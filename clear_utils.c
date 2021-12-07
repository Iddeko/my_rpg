/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** clear_utils
*/

#include "my_rpg.h"

void clear_framebuffer(framebuffer_t *fb, int width, int height)
{
    for (int h = 0; h < width * height * 32 / 8; h++)
        fb->pixels[h] = 0;
}
