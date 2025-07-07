/*
** EPITECH PROJECT, 2025
** B-MUL-100-PAR-1-1-myhunter-antonin.meynadier
** File description:
** handle_events
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

#include "my_struct.h"

void handle_duck_click(window_t *wm, duck_t *duck, explosion_t *exp)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(wm->window);
    sfFloatRect bounds = sfSprite_getGlobalBounds(duck->sprite->sprite);

    if (duck->alive && sfFloatRect_contains
        (&bounds, (float)mouse.x, (float)mouse.y)) {
        duck->alive = false;
        exp->active = true;
        exp->timer = 0.5f;
        exp->pos = duck->pos;
        sfSprite_setPosition(exp->sprite->sprite, exp->pos);
    }
}

void update_cursor_sprite(ui_t *ui, window_t *wm)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(wm->window);

    ui->crosshair_pos = (sfVector2f){mouse.x, mouse.y};
    sfSprite_setPosition(ui->crosshair->sprite, ui->crosshair_pos);
}

void handle_events(window_t *wm, duck_t *duck, ui_t *ui, explosion_t *exp)
{
    while (sfRenderWindow_pollEvent(wm->window, &wm->event)) {
        if (wm->event.type == sfEvtClosed)
            sfRenderWindow_close(wm->window);
        if (wm->event.type == sfEvtKeyPressed &&
        (wm->event.key.code == sfKeyEscape || (wm->event.key.code == sfKeyD
        && sfKeyboard_isKeyPressed(sfKeyLControl))))
            sfRenderWindow_close(wm->window);
        if (wm->event.type == sfEvtMouseButtonPressed &&
            wm->event.mouseButton.button == sfMouseLeft)
            handle_duck_click(wm, duck, exp);
    }
    update_cursor_sprite(ui, wm);
}
