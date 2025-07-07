/*
** EPITECH PROJECT, 2025
** my
** File description:
** includes
*/
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#ifndef MY_H_
    #define MY_H_
int my_cat(int ac, char **av);
int my_getnbr(char const *str);
int my_put_nbr(int nb);
int my_putchar(char c);
int my_putstr(char const *str);
void my_sort_int_array(int *array, int size);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
void my_swap(int *a, int *b);
char **my_str_to_word_array(char *str);
int my_printf(const char *format, ...);
int my_put_prct(void);
int my_put_base(int nb, int base, char *charbase);
int my_put_16_min_unsigned_long(unsigned long int nb);
int my_put_16_maj(int nbr);
int my_put_16_min(int nbr);
int my_put_8(int nbr);
int my_put_u(unsigned int nbr);
int my_put_2(int nbr);
int flag_p(void *ptr);

#endif /* !MY_H_ */
