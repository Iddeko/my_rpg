/*
** EPITECH PROJECT, 2022
** my_rpg_temp
** File description:
** csfml_utils
*/

#include "csfml_libs.h"
#include "csfml_utils.h"

sfVector2f itofv2(sfVector2i vector)
{
    sfVector2f result;

    result.x = vector.x;
    result.y = vector.y;
    return (result);
}

sfVector2f utofv2(sfVector2u vector)
{
    sfVector2f result;

    result.x = vector.x;
    result.y = vector.y;
    return (result);
}

object create_object(char *path, sfVector2f scale, sfVector2f pos)
{
    object new_object;

    new_object.sprite = sfSprite_create();
    new_object.texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(new_object.sprite, new_object.texture, 0);
    sfSprite_setScale(new_object.sprite, scale);
    sfSprite_setPosition(new_object.sprite, pos);
    return (new_object);
}

void destroy_object(object object)
{
    sfSprite_destroy(object.sprite);
    sfTexture_destroy(object.texture);
}
