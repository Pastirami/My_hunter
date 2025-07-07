/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell1-antonin.meynadier
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

int my_getnbr(char const *str);
int my_put_nbr(int nb);
int my_putchar(char c);
int my_putstr(char const *str);
int my_show_word_array(char *const *tab);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char const *src);
char *my_strdup(char const *src);
int my_strlen(char const *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
void throw_error(char *error);
char **my_str_to_word_array(char const *str, char const *delims);
void free_word_array(char **array);
char *my_heapcat(char *dest, char const *src);

#endif /* MY_H_ */
