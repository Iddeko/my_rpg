/*
** EPITECH PROJECT, 2022
** my_rpg_temp
** File description:
** mouse
*/

#ifndef MOUSE_H_
    #define MOUSE_H_

    #include "csfml_libs.h"

    sfSprite *setup_mouse(void);
    void draw_mouse(sfRenderWindow *window, sfSprite *mouse);

#endif /* !MOUSE_H_ */
