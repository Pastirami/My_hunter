/*
** EPITECH PROJECT, 2025
** moove
** File description:
** my_struct.h
*/
#include <stdarg.h>

#ifndef MY_STRUCT_H_
    #define MY_STRUCT_H_

int my_print_char(va_list args);
int my_print_str(va_list args);
int my_print_nbr(va_list args);
int my_print_prct(va_list args);
int my_print_unsigned(va_list args);
int my_print_octal(va_list args);
int my_print_hex(va_list args);
int my_print_hex_maj(va_list args);
int my_print_binaire(va_list args);
int my_print_adress(va_list args);

typedef struct my_flags_s {
    char caracter;
    int (*pf)(va_list);
} my_flags_t;

my_flags_t const my_tab_flags[] = {
    {'c', my_print_char},
    {'s', my_print_str},
    {'d', my_print_nbr},
    {'i', my_print_nbr},
    {'%', my_print_prct},
    {'u', my_print_unsigned},
    {'o', my_print_octal},
    {'x', my_print_hex},
    {'X', my_print_hex_maj},
    {'b', my_print_binaire},
    {'p', my_print_adress},
};
#endif /* !MY_STRUCT_H_PRINTF */
