/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** event_handler
*/

#include "my_rpg.h"

void event_handler(env_t env)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(env.window, &event)) {
        if (event.type == sfEvtClosed || event.key.code == sfKeyEscape)
            sfRenderWindow_close(env.window);
    }
}
