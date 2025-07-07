/*
** EPITECH PROJECT, 2025
** B-MUL-100-PAR-1-1-myhunter-antonin.meynadier
** File description:
** destroy2.c
*/

#include <stdlib.h>
#include "my.h"
#include "macros.h"
#include "my_struct.h"

void destroy_ui(ui_t *ui)
{
    if (!ui)
        return;
    destroy_sprite(ui->background);
    destroy_sprite(ui->crosshair);
    free(ui);
}

void destroy_duck(duck_t *duck)
{
    if (!duck)
        return;
    destroy_sprite(duck->sprite);
    free(duck);
}

void destroy_explosion(explosion_t *exp)
{
    if (!exp)
        return;
    destroy_sprite(exp->sprite);
    free(exp);
}
