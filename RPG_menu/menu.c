/*
** EPITECH PROJECT, 2021
** menu - main loop
** File description:
** setup and main loop
*/

#include "include/includes.h"

sfRenderWindow *create_window(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.height = height;
    video_mode.width = width;
    video_mode.bitsPerPixel = 16;


    window = sfRenderWindow_create(video_mode, "runner", sfDefaultStyle, NULL);
    return (window);
}

sfSprite *setup_mouse(void)
{
    sfSprite *mouse = sfSprite_create();
    sfTexture *tex = sfTexture_createFromFile("sprites/cursors.png", NULL);
    sfSprite_setTexture(mouse, tex, 0);
    return (mouse);
}

sfVector2f itofv2(sfVector2i vector)
{
    sfVector2f result;
    result.x = vector.x;
    result.y = vector.y;
    return (result);
}

void draw_mouse(sfRenderWindow *window, sfSprite *mouse)
{
    sfVector2f mousepos;
    mousepos = itofv2(sfMouse_getPositionRenderWindow(window));
    sfSprite_setPosition(mouse, mousepos);
    sfRenderWindow_drawSprite(window, mouse, NULL);
}

int wich_slot_w(int i, sfVector2i mousepos)
{
    if (mousepos.x >= 74 && mousepos.x <= 174) return(1 + 15 * i);
    if (mousepos.x >= 194 && mousepos.x <= 294) return(2 + 15 * i);
    if (mousepos.x >= 314 && mousepos.x <= 414) return(3 + 15 * i);
    if (mousepos.x >= 434 && mousepos.x <= 534) return(4 + 15 * i);
    if (mousepos.x >= 554 && mousepos.x <= 654) return(5 + 15 * i);
    if (mousepos.x >= 674 && mousepos.x <= 774) return(6 + 15 * i);
    if (mousepos.x >= 794 && mousepos.x <= 894) return(7 + 15 * i);
    if (mousepos.x >= 914 && mousepos.x <= 1014) return(8 + 15 * i);
    if (mousepos.x >= 1034 && mousepos.x <= 1134) return(9 + 15 * i);
    if (mousepos.x >= 1154 && mousepos.x <= 1254) return(10 + 15 * i);
    if (mousepos.x >= 1274 && mousepos.x <= 1374) return(11 + 15 * i);
    if (mousepos.x >= 1394 && mousepos.x <= 1494) return(12 + 15 * i);
    if (mousepos.x >= 1514 && mousepos.x <= 1614) return(13 + 15 * i);
    if (mousepos.x >= 1634 && mousepos.x <= 1734) return(14 + 15 * i);
    if (mousepos.x >= 1754 && mousepos.x <= 1854) return(15 + 15 * i);
    return (0);
}

int wich_slot_h(sfVector2i mousepos)
{
    if (mousepos.y >= 81 && mousepos.y <= 181)
        return(wich_slot_w(0, mousepos));
    if (mousepos.y >= 201 && mousepos.y <= 301)
        return(wich_slot_w(1, mousepos));
    if (mousepos.y >= 321 && mousepos.y <= 421)
        return(wich_slot_w(2, mousepos));
    if (mousepos.y >= 441 && mousepos.y <= 541)
        return(wich_slot_w(3, mousepos));
    if (mousepos.y >= 561 && mousepos.y <= 661)
        return(wich_slot_w(4, mousepos));
    if (mousepos.y >= 681 && mousepos.y <= 781)
        return(wich_slot_w(5, mousepos));
    if (mousepos.y >= 801 && mousepos.y <= 901)
        return(wich_slot_w(6, mousepos));
    if (mousepos.y >= 921 && mousepos.y <= 1021)
        return(wich_slot_w(7, mousepos));
    return(0);
}

int get_slot_pos_y(int slot, sfRenderWindow *window)
{
    if (slot == 0) return (sfMouse_getPositionRenderWindow(window).y - 50);
    if (slot >= 1 && slot <= 15) return (81);
    if (slot >= 16 && slot <= 30) return (201);
    if (slot >= 31 && slot <= 45) return (321);
    if (slot >= 46 && slot <= 60) return (441);
    if (slot >= 61 && slot <= 75) return (561);
    if (slot >= 76 && slot <= 90) return (681);
    if (slot >= 91 && slot <= 105) return (801);
    if (slot >= 106 && slot <= 120) return (921);
    return (1080);
}

int get_slot_pos_x(int slot, sfRenderWindow *window)
{
    if (slot == 0) return (sfMouse_getPositionRenderWindow(window).x - 50);
    slot = slot % 15;
    if (slot == 1) return (74);
    if (slot == 2) return (194);
    if (slot == 3) return (314);
    if (slot == 4) return (434);
    if (slot == 5) return (554);
    if (slot == 6) return (674);
    if (slot == 7) return (794);
    if (slot == 8) return (914);
    if (slot == 9) return (1034);
    if (slot == 10) return (1154);
    if (slot == 11) return (1274);
    if (slot == 12) return (1394);
    if (slot == 13) return (1514);
    if (slot == 14) return (1634);
    if (slot == 0) return (1754);
    return (0);
}

void select_slot(sfRenderWindow *window, int slot)
{
    int pos_x = get_slot_pos_x(slot, window);
    int pos_y = get_slot_pos_y(slot, window);
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("sprites/select.png", NULL);
    sfVector2f pos = {pos_x, pos_y};
    if (slot != 0) {
        sfSprite_setTexture(sprite, texture, 0);
        sfSprite_setPosition(sprite, pos);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfSprite_destroy(sprite);
        sfTexture_destroy(texture);
    }
}

int my_strlen(char *str)
{
    int i = 0;
    for (; str[i] != '\0'; i++);
    return (i);
}

char *my_strdup(char *str)
{
    char *result = malloc(sizeof (char) * my_strlen(str) + 1);
    for (int i = 0; str[i] != '\0'; i++)
        result[i] = str[i];
    result[my_strlen(str)] = '\0';
    return (result);
}

struct item *swap_items(int origin, int dest, struct item *items)
{
    struct item temp = items[dest];
    items[dest] = items[origin];
    items[origin] = temp;
    return (items);
}

struct item *add_items(int origin, int dest, struct item *items)
{
    items[dest].quantity += items[origin].quantity;
    items[origin].quantity = 0;
    items[origin].type = NOTHING;
    items[origin].sprite = NULL;
    return (items);
}

struct item *split_item(int origin, int dest, struct item *items, int number)
{
    items[dest].quantity = number;
    items[origin].quantity = items[origin].quantity - number;
    items[dest].sprite = sfSprite_copy(items[origin].sprite);
    items[dest].type = items[origin].type;
    return (items);
}

struct item *level_items(int dest, int origin, int max, struct item *items)
{
    if (items[dest].type != items[origin].type) {
        items[dest].sprite = sfSprite_copy(items[origin].sprite);
        items[dest].type = items[origin].type;
    }
    items[dest].quantity = items[origin].quantity - max + items[dest].quantity;
    items[origin].quantity = max;
}

struct item *get_event(sfRenderWindow *window, struct item *items)
{
    sfEvent event;
    sfVector2i mousepos = sfMouse_getPositionRenderWindow(window);
    static short pres;
    static int pressed;
    static int slot;
    while (sfRenderWindow_pollEvent(window, &event)) {
        slot = wich_slot_h(mousepos);
        if (event.key.code == sfKeyEscape || event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if ((event.type == sfEvtMouseButtonPressed & slot != 0)) {
            pres = 1;
            pressed = slot;
            if (event.mouseButton.button == 0)
                swap_items(slot, 0, items);
            if (event.mouseButton.button == 1)
                split_item(slot, 0, items, items[slot].quantity / 2);
        }
        if (event.type == sfEvtMouseButtonReleased && pres == 1) {
            pres = 0;
            if (items[slot].type != items[0].type && slot != 0)
                swap_items(slot, 0, items);
            if (items[slot].type == items[0].type && slot != 0)
                add_items(0, slot, items);
            if (items[pressed].type != items[0].type && slot == 0)
                swap_items(pressed, 0, items);
            if (items[pressed].type == items[0].type && slot == 0)
                add_items(0, pressed, items);
            if (items[slot].quantity > STACK_SIZE)
                level_items(pressed, slot, STACK_SIZE, items);
        }
    }
    if (pres == 1)
        select_slot(window, slot);
    return(items);
}

void clear_window(sfRenderWindow *window)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("sprites/bground.png", NULL);
    sfSprite_setTexture(sprite, texture, 0);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}

char *my_itos(int i)
{
    int n = 0;
    char *result;
    int temp = i;
    for (n = 0; temp != 0; n++)
        temp /= 10;
    result = malloc(sizeof(char) * n + 1);
    for (int j = 0; j < n; j ++) {
        result[n - j - 1] = (i % 10) + '0';
        i = i / 10;
    }
    result[n] = '\0';
    return (result);
}

void draw_end_at(sfRenderWindow *window, struct item item)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("font.TTF");
    sfVector2f origin = {my_strlen(my_itos(item.quantity)) * 15, 30};
    sfVector2f pos = sfSprite_getPosition(item.sprite);
    pos.x += 100;
    pos.y += 100;
    sfText_setFont(text, font);
    sfText_setString(text, my_itos(item.quantity));
    sfText_setCharacterSize(text, 25);
    sfText_setColor(text, sfWhite);
    sfText_setOutlineThickness(text, 1);
    sfText_setOutlineColor(text, sfBlack);
    sfText_setOrigin(text, origin);
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}

void print_item(sfRenderWindow *window, struct item item, sfVector2f pos)
{
    sfVector2f scale = {SCALEX, SCALEY};
    sfVector2f mvt;
    mvt.x = (pos.x - sfSprite_getPosition(item.sprite).x) / 3;
    mvt.y = (pos.y - sfSprite_getPosition(item.sprite).y) / 3;
    sfSprite_move(item.sprite, mvt);
    sfSprite_setScale(item.sprite, scale);
    sfRenderWindow_drawSprite(window, item.sprite, NULL);
}

void draw_items(sfRenderWindow *window, struct item *items)
{
    sfVector2f pos = {0, 0};

    for (int i = NB_SLOTS - 1; i >= 0; i--) {
        if (items[i].quantity != 0) {
            pos.x = get_slot_pos_x(i, window);
            pos.y = get_slot_pos_y(i, window);
            print_item(window, items[i], pos);
            draw_end_at(window, items[i]);
        }
    }
}

struct item *menu(sfRenderWindow *window, struct item *items)
{
    sfSprite *mouse = setup_mouse();
    while (sfRenderWindow_isOpen(window)) {
        clear_window(window);
        get_event(window, items);
        draw_items(window, items);
        draw_mouse(window, mouse);
        sfRenderWindow_display(window);
    }
    return (items);
}


struct item *create_items(void)
{
    struct item *result = malloc(sizeof (struct item) * NB_SLOTS);
    for (int i = 0; i < NB_SLOTS; i++) {
        result[i].quantity = 0;
        result[i].type = NOTHING;
        result[i].sprite = sfSprite_create();
    }
    return (result);
}

sfSprite *create_yellow_flower(sfSprite *sprite)
{
    sfTexture *texture = sfTexture_createFromFile("y_flower.png", NULL);
    sfSprite_setTexture(sprite, texture, 0);
    return (sprite);
}

int main(void)
{
    struct item *items = create_items();
    sfRenderWindow *window = create_window(1920, 1080);
    sfVector2f pos = {970, 540};
    //sfVector2f pos = {0, 0};
    int i = 1;
    for (; i < 121; i++) {
        items[i].quantity = (i * (i + i / 2) + 1) % 255;
        items[i].type = FLOWER_YELLOW;
        items[i].sprite = create_yellow_flower(items[i].sprite);
        //pos.x = get_slot_pos_x(i, window);
        //pos.y = get_slot_pos_y(i, window);
        sfSprite_setPosition(items[i].sprite, pos);
    }
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setMouseCursorVisible(window, 0);
    menu(window, items);
    return (0);
}
