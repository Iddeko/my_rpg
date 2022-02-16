/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** pause_menu
*/

#include "csfml_libs.h"
#include "mouse.h"
#include "keyboard.h"
#include "csfml_utils.h"

#include <stdlib.h>

int get_pause_event(sfRenderWindow *window, char *keys)
{
    sfEvent event;
    sfVector2i mousepos = sfMouse_getPositionRenderWindow(window);
    int close = 0;
    while (sfRenderWindow_pollEvent(window, &event)) {
        keys = get_keyboard_input(event, keys);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (ESC == PRESS)
            close = 1;
    }
    return(close);
}

void pause_menu(sfRenderWindow *window, char *keys)
{
    object button1 = create_object("sprites/Rectangle_button.png", VC{0.2, 0.2}, VC{1920/2 - (2000*0.2)/2, 1080/2 - (800*0.2)*1.2});
    object button2 = create_object("sprites/Rectangle_button.png", VC{0.2, 0.2}, VC{1920/2 - (2000*0.2)/2, 1080/2});
    object button3 = create_object("sprites/Rectangle_button.png", VC{0.2, 0.2}, VC{1920/2 - (2000*0.2)/2, 1080/2 + (800*0.2)*1.2});
    object pause = create_object("sprites/pause_menu.png", VC{1, 1}, VC{0, 0});
    object bg = create_object("sprites/ye_olde_map.png", VC{5, 5}, VC{90, 0});
    sfSprite *mouse = setup_mouse();
    int close = 0;

    while (close == 0) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, bg.sprite, NULL);
        sfRenderWindow_drawSprite(window, pause.sprite, NULL);
        sfRenderWindow_drawSprite(window, button1.sprite, NULL);
        sfRenderWindow_drawSprite(window, button2.sprite, NULL);
        sfRenderWindow_drawSprite(window, button3.sprite, NULL);
        close = get_pause_event(window, keys);
        draw_mouse(window, mouse);
        sfRenderWindow_display(window);
    }
    destroy_object(button1);
    destroy_object(button2);
    destroy_object(button3);
    destroy_object(pause);
    destroy_object(bg);
}
