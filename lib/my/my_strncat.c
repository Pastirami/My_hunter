/*
** EPITECH PROJECT, 2025
** lib
** File description:
** function.c
*/

#include <stdlib.h>
#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    char *result = NULL;
    int index = 0;

    result = malloc(sizeof(char) * (my_strlen(dest) + nb + 1));
    for (int i = 0; dest[i] != '\0'; ++i) {
        result[i] = dest[i];
    }
    for (int i = my_strlen(dest) + 1; i < my_strlen(dest) + nb; ++i) {
        result[i] = src[index];
    }
    result[my_strlen(dest) + nb] = '\0';
    return result;
}
