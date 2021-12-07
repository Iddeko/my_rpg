/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** main
*/

#include "my_rpg.h"
#include "my.h"

void main_loop(env_t env)
{
    while (sfRenderWindow_isOpen(env.window)) {
        event_handler(env);
        update_display(env, env.fb->height, env.fb->width);
        clear_framebuffer(env.fb, env.fb->width, env.fb->height);
    }
}

void update_display(env_t env, int high, int width)
{
    sfTexture_updateFromPixels(env.texture, env.fb->pixels, width, high, 0, 0);
    sfRenderWindow_clear(env.window, sfBlack);
    sfRenderWindow_drawSprite(env.window, env.sprite, NULL);
    sfRenderWindow_display(env.window);
}

int launcher(void)
{
    env_t env;

    env.window = create_window(WINDOW_WIDTH, WINDOW_HEIGHT);
    env.fb = framebuffer_create(WINDOW_WIDTH, WINDOW_HEIGHT);
    env.texture = sfTexture_create(WINDOW_WIDTH, WINDOW_HEIGHT);
    env.sprite = sfSprite_create();
    env.clock = sfClock_create();
    sfRenderWindow_setFramerateLimit(env.window, 60);
    sfSprite_setTexture(env.sprite, env.texture, sfTrue);
    if (!env.window)
        return (84);
    main_loop(env);
    free(env.fb->pixels);
    free(env.fb);
    sfRenderWindow_destroy(env.window);
    sfTexture_destroy(env.texture);
    sfSprite_destroy(env.sprite);
    return (0);
}

int main(int argc, char **argv)
{
    if (argc < 1) {
        if (argv[1][0] == '-' && argv[1][1] == 'h')
            return (write_usage());
        else
            return (84);
    }
    if (argc == 1) {
        launcher();
        return (0);
    } else {
        return (84);
    }
}
