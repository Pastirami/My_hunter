/*
** EPITECH PROJECT, 2025
** my_str_to_word_array
** File description:
** my str to word array
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "my.h"

static bool is_alphanum(char c, char const *delims)
{
    for (int i = 0; delims[i] != '\0'; ++i) {
        if (c == delims[i] || c == '\0') {
            return false;
        }
    }
    return true;
}

static int count_words(char const *str, char const *delims)
{
    int y = 0;
    int lenstr = my_strlen(str);

    for (int i = 0; i < lenstr; i++) {
        if (is_alphanum(str[i], delims) && (i == 0
            || !is_alphanum(str[i - 1], delims))) {
            y++;
        }
    }
    return y;
}

static int len_word(int b, char const *str, char const *delims)
{
    int len = 0;

    while (is_alphanum(str[b], delims)) {
        len++;
        b++;
    }
    return len;
}

static char *extract_word(int b, int length, char const *str)
{
    char *word = malloc(sizeof(char) * (length + 1));

    if (word == NULL) {
        return NULL;
    }
    for (int i = 0; i < length; ++i) {
        word[i] = str[b + i];
    }
    word[length] = '\0';
    return word;
}

char **my_str_to_word_array(char const *str, char const *delims)
{
    int word_count = count_words(str, delims);
    char **array = malloc((word_count + 1) * sizeof(char *));
    int pos = 0;
    int len = 0;

    if (array == NULL || str == NULL) {
        return NULL;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_alphanum(str[i], delims)) {
            len = len_word(i, str, delims);
            array[pos] = extract_word(i, len, str);
            pos++;
            i += len - 1;
        }
    }
    array[pos] = NULL;
    return array;
}
