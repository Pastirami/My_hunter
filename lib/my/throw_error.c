/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell1-antonin.meynadier
** File description:
** throw_error
*/

#include <unistd.h>
#include "my.h"

void throw_error(char *error)
{
    write(2, error, my_strlen(error));
}
