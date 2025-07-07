/*
** EPITECH PROJECT, 2025
** strcpy
** File description:
** my_strcpy
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int end = 0;
    int len = my_strlen(src);

    if (len < n)
        n = len;
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
        end = i;
    }
    dest[end] = '\0';
    return dest;
}
