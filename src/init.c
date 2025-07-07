/*
** EPITECH PROJECT, 2025
** B-MUL-100-PAR-1-1-myhunter-antonin.meynadier
** File description:
** init.c
*/
#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics/Rect.h>

#include "my.h"
#include "my_struct.h"
#include "macros.h"

static window_t *init_window(void)
{
    window_t *wm = malloc(sizeof(window_t));

    if (!wm)
        return NULL;
    wm->mode = (sfVideoMode){WINDOW_WIDTH, WINDOW_HEIGHT, 32};
    wm->window = sfRenderWindow_create(wm->mode, "My Hunter", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(wm->window, 20);
    if (!wm->window)
        return NULL;
    return wm;
}

static clocked_t *init_clock(void)
{
    clocked_t *clk = malloc(sizeof(clocked_t));

    if (!clk)
        return NULL;
    clk->clock = sfClock_create();
    if (!clk->clock)
        return NULL;
    clk->delta_time = 0;
    return clk;
}

bool init_tools(window_t **wm, clocked_t **clock)
{
    *wm = init_window();
    if (!*wm)
        return false;
    *clock = init_clock();
    if (!*clock)
        return false;
    return true;
}

static sprite_t *init_background(void)
{
    sprite_t *bg = malloc(sizeof(sprite_t));
    sfFloatRect bounds;

    if (!bg)
        return NULL;
    bg->texture = sfTexture_createFromFile(BG_IMAGE_PATH, NULL);
    if (!bg->texture)
        return NULL;
    bg->sprite = sfSprite_create();
    sfSprite_setTexture(bg->sprite, bg->texture, sfTrue);
    bounds = sfSprite_getGlobalBounds(bg->sprite);
    sfSprite_setScale(bg->sprite, (sfVector2f){
        (float)WINDOW_WIDTH / bounds.width,
        (float)WINDOW_HEIGHT / bounds.height
    });
    return bg;
}

static sprite_t *init_crosshair(void)
{
    sprite_t *cs = malloc(sizeof(sprite_t));
    sfFloatRect lb;

    if (!cs)
        return NULL;
    cs->texture = sfTexture_createFromFile(CROSSHAIR_IMAGE_PATH, NULL);
    if (!cs->texture) {
        free(cs);
        return NULL;
    }
    cs->sprite = sfSprite_create();
    sfSprite_setTexture(cs->sprite, cs->texture, sfTrue);
    sfSprite_setScale(cs->sprite, (sfVector2f){0.1f, 0.1f});
    lb = sfSprite_getLocalBounds(cs->sprite);
    sfSprite_setOrigin(cs->sprite, (sfVector2f)
        {lb.width / 2.0f, lb.height / 2.0f});
    return cs;
}

static explosion_t *init_explosion_sprite(explosion_t *exp)
{
    exp->sprite->texture =
        sfTexture_createFromFile(EXPLOSION_IMAGE_PATH, NULL);
    if (!exp->sprite->texture)
        return NULL;
    exp->sprite->sprite = sfSprite_create();
    if (!exp->sprite->sprite)
        return NULL;
    sfSprite_setTexture(exp->sprite->sprite, exp->sprite->texture, sfTrue);
    sfSprite_setScale(exp->sprite->sprite, (sfVector2f) {0.15f, 0.15f});
    return exp;
}

explosion_t *init_explosion(void)
{
    explosion_t *exp = malloc(sizeof(explosion_t));
    sfFloatRect bounds;

    if (!exp)
        return NULL;
    exp->sprite = malloc(sizeof(sprite_t));
    if (!exp->sprite)
        return NULL;
    exp = init_explosion_sprite(exp);
    bounds = sfSprite_getGlobalBounds(exp->sprite->sprite);
    sfSprite_setOrigin(exp->sprite->sprite, (sfVector2f)
        {bounds.width / 2, bounds.height / 2});
    exp->active = false;
    exp->timer = 0;
    exp->pos = (sfVector2f) {0, 0};
    return exp;
}

duck_t *init_duck(void)
{
    duck_t *duck = malloc(sizeof(duck_t));

    if (!duck)
        return NULL;
    duck->sprite = malloc(sizeof(sprite_t));
    if (!duck->sprite)
        return NULL;
    duck->sprite->texture = sfTexture_createFromFile(DUCK_IMAGE_PATH, NULL);
    if (!duck->sprite->texture)
        return NULL;
    duck->sprite->sprite = sfSprite_create();
    duck->sprite->rect = (sfIntRect) {0, 0, 110, 110};
    sfSprite_setTexture(duck->sprite->sprite, duck->sprite->texture, sfTrue);
    sfSprite_setTextureRect(duck->sprite->sprite, duck->sprite->rect);
    duck->pos = (sfVector2f){-110, rand() % (WINDOW_HEIGHT - 110)};
    duck->velocity = (sfVector2f){150.0f, 30.0f};
    duck->respawn_timer = 0;
    duck->alive = true;
    sfSprite_setPosition(duck->sprite->sprite, duck->pos);
    return duck;
}

ui_t *init_ui(void)
{
    ui_t *ui = malloc(sizeof(ui_t));

    if (!ui)
        return NULL;
    ui->background = init_background();
    ui->crosshair = init_crosshair();
    ui->crosshair_pos = (sfVector2f){0, 0};
    if (!ui->background || !ui->crosshair)
        return NULL;
    return ui;
}
