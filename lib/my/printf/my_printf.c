/*
** EPITECH PROJECT, 2025
** B-CPE-101-PAR-1-1-miniprintf-thibault.miallet
** File description:
** main.c
*/
#include "include/my.h"
#include "include/my_struct.h"
#include <stdarg.h>

void my_params(const char *format, int *i, va_list cur_arg, int *count)
{
    char the_char = format[*i + 1];

    for (int j = 0; my_tab_flags[j].caracter != 0; j++) {
        if (my_tab_flags[j].caracter == the_char) {
            *count += my_tab_flags[j].pf(cur_arg);
            *i += 1;
            return;
        }
    }
}

int my_printf(const char *format, ...)
{
    va_list cur_arg;
    int count = 0;

    va_start(cur_arg, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            my_params(format, &i, cur_arg, &count);
        } else {
            my_putchar(format[i]);
            count++;
        }
    }
    va_end(cur_arg);
    return count;
}
