/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** structs configuration (header file)
*/

# ifndef STRUCTS_TETRIS_H
# define STRUCTS_TETRIS_H

struct 	keym_t;
struct 	map_t;
struct 	tetriminos_t;
struct 	config_t;
struct 	pos_t;
struct 	stats_t;
struct 	main_t;

typedef struct keym_t {
	char 	c;
	char 	*display;
} 	keym_t;

typedef struct map_t {
	int 	color;
	char 	**form;
	int 	pos_x;
	int 	pos_y;
	int 	stop;
	struct map_t *next;
}	map_t;

typedef struct tetriminos_t {
	int 	id;
	int 	height;
	int 	width;
	int 	color;
	int 	invalid;
	char 	*name;
	char 	**form;
	char 	*path;
	struct tetriminos_t *next;
} 	tetriminos_t;

typedef struct config_t {
	keym_t 	k_left;
	keym_t 	k_right;
	keym_t 	k_turn;
	keym_t 	k_drop;
	keym_t 	k_quit;
	keym_t 	k_pause;
	int 	next;
	int 	debug;
	int 	level;
	int 	size_w;
	int 	size_h;
	int 	nb_tetri;
} 	config_t;

typedef struct stats_t {
	int 	level;
	int 	high_score;
	int 	score;
	int 	lines;
	int 	timer;
}	stats_t;

typedef struct main_t {
	int 		ac;
	char 		**av;
	tetriminos_t 	*tetri;
	map_t		*map;
	config_t 	*config;
	stats_t 	*stats;
} 	main_t;

# endif
