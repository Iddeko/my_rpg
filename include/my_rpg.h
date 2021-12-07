/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** my rpg header
*/

#ifndef MY_RPG_H_
    #define MY_RPG_H_

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window/Export.h>
    #include <SFML/Window/Keyboard.h>

    #include <stdlib.h>

    #define WINDOW_HEIGHT 1080
    #define WINDOW_WIDTH 1920

typedef struct framebuffer_s {
    int width;
    int height;
    unsigned char *pixels;
}framebuffer_t;

typedef struct environnement_s {
    framebuffer_t *fb;
    sfRenderWindow *window;
    sfTexture *texture;
    sfSprite *sprite;
    sfClock *clock;
}env_t;

int write_usage(void);
int launcher(void);
void event_handler(env_t env);
void main_loop(env_t);
void update_display(env_t, int, int);
void clear_framebuffer(framebuffer_t *, int, int);
framebuffer_t *framebuffer_create(unsigned int, unsigned int);
sfRenderWindow *create_window(unsigned int, unsigned int);
sfColor setup_color(int, int, int, int);

#endif /* MY_RPG_H_ */
