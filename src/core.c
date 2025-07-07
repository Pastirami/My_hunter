/*
** EPITECH PROJECT, 2025
** B-MUL-100-PAR-1-1-myhunter-antonin.meynadier
** File description:
** core
*/

#include "my.h"
#include "macros.h"
#include "my_struct.h"

int core_func(void)
{
    window_t *wm = NULL;
    clocked_t *clock = NULL;
    ui_t *ui = NULL;
    duck_t *duck = NULL;

    if (!init_tools(&wm, &clock))
        return ERROR_VALUE;
    ui = init_ui();
    duck = init_duck();
    duck->explosion = init_explosion();
    if (!ui || !duck || !duck->explosion)
        return ERROR_VALUE;
    game_loop(wm, duck, ui, clock);
    destroy_window(wm);
    destroy_clock(clock);
    destroy_ui(ui);
    destroy_explosion(duck->explosion);
    destroy_duck(duck);
    return SUCCESS_VALUE;
}
