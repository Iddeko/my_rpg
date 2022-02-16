/*
** EPITECH PROJECT, 2022
** my_rpg_temp
** File description:
** mouse
*/

#include "csfml_libs.h"

sfVector2f itofv2(sfVector2i vector)
{
    sfVector2f result;

    result.x = vector.x;
    result.y = vector.y;
    return (result);
}

sfSprite *setup_mouse(void)
{
    sfSprite *mouse = sfSprite_create();
    sfTexture *tex = sfTexture_createFromFile("sprites/cursors.png", NULL);

    sfSprite_setTexture(mouse, tex, 0);
    return (mouse);
}

void draw_mouse(sfRenderWindow *window, sfSprite *mouse)
{
    sfVector2f mousepos;

    mousepos = itofv2(sfMouse_getPositionRenderWindow(window));
    sfSprite_setPosition(mouse, mousepos);
    sfRenderWindow_drawSprite(window, mouse, NULL);
}
