/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** structs configuration (header file)
*/

# ifndef STRUCTS_TETRIS_H
# define STRUCTS_TETRIS_H

struct 	tetriminos_t;
struct 	args_t;
struct 	config_t;
struct 	main_t;

typedef struct tetriminos_t {
	int id;
	int height;
	int width;
	int color;
	int invalid;
	char *name;
	char **form;
	char *path;
	struct tetriminos_t *next;
} 	tetriminos_t;

typedef struct args_t {
	char 			*name;
	int 			has_arg;
	int 			*flag;
	int 			val;
	struct args_t 	*next;
} 	args_t;

typedef struct config_t {
	char kl;
	char kr;
	char kt;
	char kd;
	char kq;
	char kp;
	int next;
	int level;
	int size_w;
	int size_h;
	int nb_tetri;
} 	config_t;

typedef struct main_t {
	int ac;
	char **av;
	tetriminos_t *tetri;
	config_t *config;
	char **current;
	char **next;
	int pos_x;
	int pos_y;
	int debug;
	int level;
	int high_score;
	int score;
	int lines;
	int timer;
} 	main_t;

# endif
