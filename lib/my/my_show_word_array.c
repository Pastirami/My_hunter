/*
** EPITECH PROJECT, 2025
** my_show_word_array
** File description:
** my show word array
*/

#include <stddef.h>
#include "my.h"

int my_show_word_array(char *const *tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = 0; tab[i][j]; j++) {
            my_putchar(tab[i][j]);
        }
        my_putchar('\n');
    }
    return 0;
}
