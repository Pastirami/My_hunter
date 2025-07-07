/*
** EPITECH PROJECT, 2025
** strcpy
** File description:
** my_strcpy
*/

#include "my.h"
#include <stdlib.h>

char *my_strcpy(char const *src)
{
    int end = my_strlen(src);
    char *dest = NULL;

    for (int i = 0; i < end; ++i) {
        dest[i] = src[i];
    }
    dest[end] = '\0';
    return dest;
}
