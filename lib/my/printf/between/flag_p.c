/*
** EPITECH PROJECT, 2025
** B-CPE-101-PAR-1-1-myprintf-thibault.miallet
** File description:
** flag_p.c
*/
#include "../include/my.h"
#include <stdarg.h>

int my_print_adress(va_list args)
{
        void *value = va_arg(args, void *);

    return flag_p(value);
}
