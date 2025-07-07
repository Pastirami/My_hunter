/*
** EPITECH PROJECT, 2025
** my_heapcat
** File description:
** my_heapcat
*/

#include <stdlib.h>
#include "my.h"

char *my_heapcat(char *dest, char const *src)
{
    int index = 0;
    char *result = malloc
    (sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

    if (src == NULL || result == NULL) {
        free(result);
        return dest;
    }
    while (dest[index] != '\0') {
        result[index] = dest[index];
        index++;
    }
    for (int i = 0; src[i] != '\0'; ++i) {
        result[index] = src[i];
        index++;
    }
    result[index] = '\0';
    return result;
}
