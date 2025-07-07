/*
** EPITECH PROJECT, 2025
** B-MUL-100-PAR-1-1-myhunter-antonin.meynadier
** File description:
** main_loop
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

#include <SFML/Graphics.h>
#include "my.h"

static void draw_sprites(window_t *wm, duck_t *duck,
    ui_t *ui, explosion_t *explosion)
{
    sfRenderWindow_drawSprite(wm->window, ui->background->sprite, NULL);
    if (duck->alive)
        sfRenderWindow_drawSprite(wm->window, duck->sprite->sprite, NULL);
    if (explosion->active)
        sfRenderWindow_drawSprite(wm->window,
        explosion->sprite->sprite, NULL);
    sfRenderWindow_drawSprite(wm->window, ui->crosshair->sprite, NULL);
}

void game_loop(window_t *wm, duck_t *duck, ui_t *ui, clocked_t *clock)
{
    sfVector2u window_size;
    sfTime time;
    explosion_t *explosion = duck->explosion;

    sfRenderWindow_setMouseCursorVisible(wm->window, sfFalse);
    window_size = sfRenderWindow_getSize(wm->window);
    while (sfRenderWindow_isOpen(wm->window)) {
        time = sfClock_restart(clock->clock);
        clock->delta_time = time.microseconds / 1000000.0f;
        handle_events(wm, duck, ui, explosion);
        update_duck(duck, clock->delta_time, window_size);
        update_explosion(explosion, clock->delta_time);
        sfRenderWindow_clear(wm->window, sfBlack);
        draw_sprites(wm, duck, ui, explosion);
        sfRenderWindow_display(wm->window);
    }
}
