/*
** EPITECH PROJECT, 2025
** B-MUL-100-PAR-1-1-myhunter-antonin.meynadier
** File description:
** update_sprite.c
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics/Rect.h>
#include <stdbool.h>
#include <stdlib.h>

#include "my.h"
#include "my_struct.h"
#include "macros.h"

#include "my_struct.h"
#include <SFML/Graphics.h>
#include <math.h>
#include <stdlib.h>

void mouv_duck(duck_t *duck, float delta_time, sfVector2u win_size)
{
    duck->animation += delta_time;
    if (duck->animation >= 0.1f) {
        duck->sprite->rect.left += 110;
        if (duck->sprite->rect.left >= 330)
            duck->sprite->rect.left = 0;
        sfSprite_setTextureRect(duck->sprite->sprite, duck->sprite->rect);
        duck->animation = 0.0f;
    }
    duck->pos.x += duck->velocity.x * delta_time;
    duck->pos.y += duck->velocity.y * delta_time;
    if (duck->pos.y < 0)
        duck->pos.y = 0;
    if (duck->pos.y + duck->sprite->rect.height > win_size.y)
        duck->pos.y = win_size.y - duck->sprite->rect.height;
    if (duck->pos.x > win_size.x)
        duck->alive = false;
    sfSprite_setPosition(duck->sprite->sprite, duck->pos);
}

void update_duck(duck_t *duck, float delta_time, sfVector2u win_size)
{
    if (!duck->alive) {
        duck->respawn_timer += delta_time;
        if (duck->respawn_timer >= 2.0f) {
            duck->pos.x = -duck->sprite->rect.width;
            duck->pos.y = rand() % (win_size.y - duck->sprite->rect.height);
            duck->respawn_timer = 0.0f;
            duck->alive = true;
            sfSprite_setPosition(duck->sprite->sprite, duck->pos);
        }
        return;
    }
    mouv_duck(duck, delta_time, win_size);
}
