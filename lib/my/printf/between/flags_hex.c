/*
** EPITECH PROJECT, 2025
** moove
** File description:
** flags_Xxuo.c
*/
#include "../include/my.h"
#include <stdarg.h>

int my_print_hex_maj(va_list args)
{
    int nbr = va_arg(args, int);

    return my_put_16_maj(nbr);
}

int my_print_hex(va_list args)
{
    int nbr = va_arg(args, int);

    return my_put_16_min(nbr);
}

int my_print_octal(va_list args)
{
    int nbr = va_arg(args, int);

    return my_put_8(nbr);
}

int my_print_unsigned(va_list args)
{
    int nbr = va_arg(args, int);

    return my_put_u((unsigned int)nbr);
}

int my_print_binaire(va_list args)
{
    int nbr = va_arg(args, int);

    return my_put_2(nbr);
}
