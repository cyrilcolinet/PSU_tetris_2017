/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** structs configuration (header file)
*/

# ifndef STRUCTS_TETRIS_H
# define STRUCTS_TETRIS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <ncurses.h>

typedef struct tetriminos_s {
	char *name;
	char **form;
	struct tetriminos *next;
} tetriminos_t;

typedef struct config_s {

} config_t;

typedef struct main_s {
	tetriminos_t *tetri;
	config_t config;
} main_t;

# endif
