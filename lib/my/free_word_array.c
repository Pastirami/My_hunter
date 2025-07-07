/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell1-antonin.meynadier
** File description:
** free_word_array
*/

#include <stdlib.h>

void free_word_array(char **array)
{
    if (array != NULL) {
        for (int i = 0; array[i] != NULL; ++i) {
            free(array[i]);
        }
        free(array);
    }
}
