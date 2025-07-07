/*
** EPITECH PROJECT, 2025
** B-MUL-100-PAR-1-1-myhunter-antonin.meynadier
** File description:
** destroy.c
*/

#include <stdlib.h>
#include "my.h"
#include "macros.h"
#include "my_struct.h"

void destroy_sprite(sprite_t *sprite)
{
    if (!sprite)
        return;
    sfSprite_destroy(sprite->sprite);
    sfTexture_destroy(sprite->texture);
    free(sprite);
}

void destroy_window(window_t *wm)
{
    if (!wm)
        return;
    sfRenderWindow_destroy(wm->window);
    free(wm);
}

void destroy_clock(clocked_t *clk)
{
    if (!clk)
        return;
    sfClock_destroy(clk->clock);
    free(clk);
}
