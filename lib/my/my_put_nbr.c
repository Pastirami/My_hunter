/*
** EPITECH PROJECT, 2025
** put_nbr
** File description:
** to print nbr
*/

#include "my.h"

int my_put_nbr(int nb)
{
    int temp_nb = 0;
    int count = 0;

    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
        count++;
    }
    if (nb >= 10) {
        temp_nb = nb % 10;
        count += my_put_nbr(nb / 10);
        my_putchar('0' + temp_nb);
        count++;
    }
    if (nb < 10) {
        my_putchar('0' + nb);
        count++;
        }
    return count;
}
