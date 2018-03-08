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
# include <sys/stat.h>
# include <sys/types.h>
# include <ncurses.h>

typedef struct tetriminos {
	char *name;
	char **form;
	struct tetriminos *next;
} tetriminos_t;

typedef struct config {

} config_t;

typedef struct main {
	tetriminos_t *tetri;
	config_t config;
} main_t;

# endif
