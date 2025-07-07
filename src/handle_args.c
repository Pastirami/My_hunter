/*
** EPITECH PROJECT, 2025
** B-MUL-100-PAR-1-1-myhunter-antonin.meynadier
** File description:
** handle args
*/

#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>

#include "my.h"

bool handle_args(int argc, char **av)
{
    (void)av;
    if (argc > 2) {
        write(2, "To many arguments!\n", 20);
        return false;
    }
    if (argc == 1) {
        return true;
    } else {
        write(2, "invalid argument\n", 18);
        return false;
    }
    return true;
}
