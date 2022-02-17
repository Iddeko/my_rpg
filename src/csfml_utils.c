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

/*
sfText_setFont(text, font);
sfText_setCharacterSize(text, 25);
sfText_setColor(text, sfWhite);
sfText_setOutlineThickness(text, 1);
sfText_setOutlineColor(text, sfBlack);
*/

text create_text(char *font, char *string, sfVector2f origin, sfVector2f pos)
{
    text new_text;

    new_text.text = sfText_create();
    new_text.font = sfFont_createFromFile(font);
    sfText_setFont(new_text.text, new_text.font);
    sfText_setString(new_text.text, string);
    sfText_setOrigin(new_text.text, origin);
    sfText_setPosition(new_text.text, pos);
    return (new_text);
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
