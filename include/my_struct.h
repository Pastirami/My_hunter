/*
** EPITECH PROJECT, 2025
** myhunter*
** File description:
** my struc myhunter
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Clock.h>
#include <stdbool.h>

#ifndef MY_STRUCT_H
    #define MY_STRUCT_H

    #include <SFML/Graphics.h>
    #include <stdbool.h>

typedef struct sprite_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
} sprite_t;

typedef struct explosion_s {
    sprite_t *sprite;
    sfVector2f pos;
    float timer;
    bool active;
} explosion_t;

typedef struct duck_s {
    sprite_t *sprite;
    sfVector2f pos;
    sfVector2f velocity;
    explosion_t *explosion;
    float respawn_timer;
    float animation;
    bool alive;
} duck_t;

typedef struct ui_s {
    sprite_t *background;
    sprite_t *crosshair;
    sfVector2f crosshair_pos;
} ui_t;

typedef struct clocked_s {
    sfClock *clock;
    float delta_time;
} clocked_t;

typedef struct window_s {
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent event;
} window_t;

#endif // MY_STRUCT_H
