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
# include <error.h>
# include <errno.h>
# include <string.h>
# include <dirent.h>

typedef struct stat stat_t;
typedef struct dirent dir_t;

typedef struct files_t {
	int id;
	char *name;
	char *path;
	struct files_t *next;
} files_t;

typedef struct tetriminos {
	int height;
	int width;
	int color;
	int id;
	char *name;
	char **form;
	char *path;
	struct tetriminos *next;
} tetriminos_t;

typedef struct config {

} config_t;

typedef struct main {
	tetriminos_t *tetri;
	config_t config;
} main_t;

# endif
