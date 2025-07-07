/*
** EPITECH PROJECT, 2025
** B-MUL-100-PAR-1-1-myhunter-antonin.meynadier
** File description:
** main_loop
*/

#include "my_struct.h"

void update_explosion(explosion_t *exp, float delta_time)
{
    if (!exp->active)
        return;
    exp->timer -= delta_time;
    if (exp->timer <= 0.0f)
        exp->active = false;
}
