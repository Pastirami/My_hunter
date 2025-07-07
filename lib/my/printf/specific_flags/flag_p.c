/*
** EPITECH PROJECT, 2025
** flag_p
** File description:
** flag p
*/

#include <stdio.h>
#include <unistd.h>
#include "../include/my.h"

int my_put_long_unsigned_base
(unsigned long int nb, unsigned long base, char *charbase)
{
    unsigned long int temp_nb = 0;
    int count = 0;

    if (nb >= base) {
        temp_nb = nb % base;
        count += my_put_long_unsigned_base(nb / base, base, charbase);
        my_putchar(charbase[temp_nb]);
        count++;
    }
    if (nb < base) {
        my_putchar(charbase[nb]);
        count++;
    }
    return count;
}

int my_put_16_min_unsigned_long(unsigned long int nb)
{
    int return_value = my_put_long_unsigned_base(nb, 16, "0123456789abcdef");

    return return_value;
}

int flag_p(void *ptr)
{
    my_putstr("0x");
    return my_put_16_min_unsigned_long((unsigned long int)ptr);
}
