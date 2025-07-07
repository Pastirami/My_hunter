/*
** EPITECH PROJECT, 2025
** moove
** File description:
** flags_csid.c
*/
#include "../include/my.h"
#include <stdarg.h>

int my_print_char(va_list args)
{
    char c = va_arg(args, int);

    return my_putchar(c);
}

int my_print_str(va_list args)
{
    char *str = va_arg(args, char *);

    return my_putstr(str);
}

int my_print_nbr(va_list args)
{
    int nbr = va_arg(args, int);

    return my_put_nbr(nbr);
}

int my_print_prct(va_list args)
{
    (void)args;
    return my_put_prct();
}
