/*
** EPITECH PROJECT, 2025
** myhunter
** File description:
** include myhunter
*/

#ifndef MY_H
    #define MY_H

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include "../lib/my/my.h"
    #include "my_struct.h"

int core_func(void);
explosion_t *init_explosion(void);
duck_t *init_duck(void);
void game_loop(window_t *wm, duck_t *duck, ui_t *ui, clocked_t *clock);
void handle_events(window_t *wm, duck_t *duck,
    ui_t *ui, explosion_t *explosion);
void handle_duck_click(window_t *wm, duck_t *duck, explosion_t *explosion);
void update_explosion(explosion_t *exp, float delta_time);
void update_duck(duck_t *duck, float delta_time, sfVector2u win_size);
void mouv_duck(duck_t *duck, float delta_time, sfVector2u win_size);
bool init_tools(window_t **wm, clocked_t **clock);
void destroy_window(window_t *window);
void destroy_clock(clocked_t *clock);
void destroy_sprite(sprite_t *sprite);
void destroy_ui(ui_t *ui);
void destroy_duck(duck_t *duck);
void destroy_explosion(explosion_t *exp);
ui_t *init_ui(void);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
#endif // MY_H
