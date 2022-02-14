/*
** EPITECH PROJECT, 2022
** Armory - get keyboard input
** File description:
** returns a char * with the keyboard key pressed
*/

#include "libs.h"
#include "keyboard macros.h"
#include <stdlib.h>

char *press_buttons(sfEvent event, char *keys, int state)
{
    for (int i = 0; i <= sfKeyCount; i++)
        if (i == event.key.code)
            keys[i] = state;
    return (keys);
}

char *cleanup_keys(char *keys)
{
    for (int i = 0; i <= sfKeyCount + 2; i++) {
        if (keys[i] == PRESS)
            keys[i] = HELD;
        if (keys[i] == RELEASE)
            keys[i] = NHELD;
    }
}

char *get_keyboard_input(sfEvent event, char *keys)
{
    cleanup_keys(keys);
    if (event.type == sfEvtMouseButtonPressed) {
        if (event.mouseButton.button == 0)
            LCLICK = PRESS;
        if (event.mouseButton.button == 1)
            RCLICK = PRESS;
    }
    if (event.type == sfEvtMouseButtonReleased) {
        if (event.mouseButton.button == 0)
            LCLICK = RELEASE;
	    if (event.mouseButton.button == 1)
            RCLICK = RELEASE;
    }
    if (event.type == sfEvtKeyPressed) {
        keys = press_buttons(event, keys, PRESS);
    }
    if (event.type == sfEvtKeyReleased)
        keys = press_buttons(event, keys, RELEASE);
    return (keys);
}
