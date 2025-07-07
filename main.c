/*
** EPITECH PROJECT, 2025
** B-MUL-100-PAR-1-1-myhunter-antonin.meynadier
** File description:
** main.c
*/

#include <unistd.h>

#include "my.h"
#include "macros.h"

static int display_help(void)
{
    my_putstr("USAGE:\n"
    "./my_hunter - launch the game\n"
    "-h : display this help message\n");
    return SUCCESS_VALUE;
}

int main(int argc, char **argv, char **env)
{
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0)
        return display_help();
    if (env[0] == NULL) {
        return ERROR_VALUE;
    }
    if (argc != 1)
        return ERROR_VALUE;
    return core_func();
}
