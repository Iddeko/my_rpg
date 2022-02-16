/*
** EPITECH PROJECT, 2022
** menu - structures.h
** File description:
** here be definitions
*/

#ifndef structures
    #define structures

    #define NOTHING 0
    #define FLOWER_YELLOW 1
    #define FLOWER_RED 2
    #define NB_SLOTS 121
    #define STACK_SIZE 255
    #define SCALEX 1
    #define SCALEY 1

    #include "csfml_libs.h"

    struct item {
        sfSprite *sprite;
        int quantity;
        int type;
    };

#endif /* !structures */
