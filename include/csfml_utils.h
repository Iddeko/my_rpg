/*
** EPITECH PROJECT, 2022
** my_rpg_temp
** File description:
** csfml_utils
*/

#ifndef CSFML_UTILS_H_
    #define CSFML_UTILS_H_

    #include "csfml_libs.h"

    #define VC (sfVector2f)

typedef struct object_s {
    char *nom;
    sfSprite *sprite;
    sfTexture *texture;
}object;

sfVector2f itofv2(sfVector2i);
sfVector2f utofv2(sfVector2u);
object create_object(char *, sfVector2f, sfVector2f);
void destroy_object(object);

#endif /* !CSFML_UTILS_H_ */
