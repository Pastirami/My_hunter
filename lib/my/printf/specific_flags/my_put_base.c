/*
** EPITECH PROJECT, 2025
** my_put_base
** File description:
** to print from any base of number
*/
#include "../include/my.h"

int my_put_base(int nb, int base, char *charbase)
{
    int temp_nb = 0;
    int count = 0;

    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
        count++;
    }
    if (nb >= base) {
        temp_nb = nb % base;
        count += my_put_base(nb / base, base, charbase);
        my_putchar(charbase[temp_nb]);
        count++;
    }
    if (nb < base) {
        my_putchar(charbase[nb]);
        count++;
        }
    return count;
}

int my_put_16_maj(int nb)
{
    int return_value = my_put_base(nb, 16, "0123456789ABCDEF");

    return return_value;
}

int my_put_16_min(int nb)
{
    int return_value = my_put_base(nb, 16, "0123456789abcdef");

    return return_value;
}

int my_put_8(int nb)
{
    int return_value = my_put_base(nb, 8, "01234567");

    return return_value;
}
