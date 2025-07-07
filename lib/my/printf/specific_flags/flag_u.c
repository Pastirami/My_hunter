/*
** EPITECH PROJECT, 2025
** flag_u
** File description:
** flag u
*/

#include "../include/my.h"
#include <unistd.h>

int my_put_u(unsigned int nb)
{
    if (nb >= 10) {
        my_put_nbr(nb / 10);
    }
        my_putchar('0'+ (nb % 10));
    return 0;
}

int my_put_2(int nb)
{
    int return_value = my_put_base(nb, 2, "01");

    return return_value;
}
