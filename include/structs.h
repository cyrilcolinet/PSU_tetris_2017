/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** structs configuration (header file)
*/

# ifndef STRUCTS_TETRIS_H
# define STRUCTS_TETRIS_H

typedef struct files_t {
	int id;
	char *name;
	char *path;
	struct files_t *next;
} files_t;

typedef struct tetriminos {
	int id;
	int height;
	int width;
	int color;
	int invalid;
	char *name;
	char **form;
	char *path;
	struct tetriminos *next;
} tetriminos_t;

typedef struct config {
	char kl;
	char kr;
	char kt;
	char kd;
	char kq;
	char kp;
	bool next;
	int level;
	int size_w;
	int size_h;
	int nb_tetri;
} config_t;

typedef struct main {
	int ac;
	char **av;
	tetriminos_t *tetri;
	config_t config;
	char **next_form;
	char **current;
	int pos_x;
	int pos_y;
	int debug;
	int level;
	int high_score;
	int score;
	int lines;
	int timer;
} main_t;

# endif
