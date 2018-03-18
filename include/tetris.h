/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** tetris functions (header file)
*/

# ifndef TETRIS_H
# define TETRIS_H

# define READ_SIZE 			(128)
# define TETRIMINOS_DIR 	("./tetriminos/")

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
# include <getopt.h>
# include <time.h>

# include "my.h"
# include "structs.h"

typedef struct stat stat_t;
typedef struct dirent dir_t;
typedef struct option opt_t;

// tetris.c
int 		check_nb_valid(main_t *param);
int 		tetris(main_t *param);
int 		tetris_main(int ac, char **av);
void 		display_help(main_t *param);

// -- MANAGERS

// map_struct_manager.c
void 		new_fixed_tetrimino(main_t *param, int stop);

// --- ARGUMENTS

// initialise_config.c
void 		initialise_config(main_t *param);

// configure_args.c
void 		execute_action_on_flag(int res, main_t *param);
void 		arguments_manager(main_t *param);

// flags/key_manager.c
char 		check_multitouch(void);
char 		*configure_key_display(char c);
keym_t 		config_key(char c);
void 		free_keymaps(main_t *param);

// flags/key_flags.c
void 		manage_level_flag(main_t *param);
char 		**map_change_error(int count, main_t *param);
void 		change_map_size(main_t *param);
void 		key_error(char multi, main_t *param);
void 		change_key(int res, main_t *param);

// --- DEBUG

// debug_mode.c
void 		key_display(main_t *param);
void 		valid_info_display(tetriminos_t *tmp);
void 		tetriminos_display(main_t *param);
void 		debug_mode(main_t *param);

// --- MAP

// new_form.c
map_t 		*add_new_form_map(map_t *tmp);

// display_score.c
int 		nb_length(int nb);
void 		display_score_value(main_t *param);
void 		display_score(main_t *param);

// display_next_tetri.c
void 		display_next_tetri_size_one(int n, int b);
void 		display_next_tetri(main_t *param, map_t *next);

// display_map.c
void 		display_map(main_t *param);

// display_game.c
void 		ini_map(void);
void 		display_all(main_t *param);
void 		display_game(main_t *param);

// display_form.c
int 		print_space(map_t *tmp, int i, int j, int nb);
void 		display_form(map_t *tmp);

// create_tetris_title.c && all letters
void 		create_tetris_title(void);
void 		letter_one(void);
void 		letter_two(void);
void 		letter_three(void);
void 		letter_four(void);
void 		letter_five(void);
void 		letter_six(void);

// create_random_tetri.c
char 		**copy_form(char **str, char **tmp);
tetriminos_t 	*check_occurence(main_t *param, int nb);
map_t 		*create_random_tetri(main_t *param);

// --- PLAYER_ACTION

// deplacement.c
int 		get_len(map_t *tmp);
void 		deplacement(main_t *param, map_t *tmp, int n);

// rotation.c
char 		**copie_and_rotate(char **n, char **form, int i, int j);
int 		get_len_form(char **form);
char 		**malloc_new(char **n, char **form, int len, int nb);
void 		rotation(main_t *param, int n, map_t *tmp);

// --- SORTING

// list_manager.c


// --- TETRIMINOS

// parse_file.c
char 		*get_first_line(char *file);
int 		set_first_values(tetriminos_t *tmp, char *path);
char 		*parse_filename(char *file);
char 		*clear_str(char *str);
char 		**get_tetrimino_form(char *file, int heigth);

// load_tetriminos.c
void 		fill_struct(main_t *param, char *path, char *file);
void 		setup_tetrimino(dir_t *dirent, main_t *param);
int 		get_files(main_t *param);
int 		config_tetriminos(main_t *param);
void 		free_tetriminos(main_t *param);

// error/error_size_color.c
int 		error_size_color(char *str);

// error/error_form.c
void 		check_character(tetriminos_t *tmp, main_t *param);
void 		error_form(main_t *param);

// -- UTILS

// get_next_line.c
char 		*my_realloc2(char *ptr, unsigned int size);
int 		get_character(int fd, char *str);
char 		*return_freed(char *ptr, char *ret);
char 		*get_next_line(int fd);

// struct_utils.c
void 		free_map(main_t *param);
void 		free_all(main_t *param);
void 		configure_tetri_struct(main_t *param);
void		configure_stats_struct(main_t *param);
main_t 		*configure(void);

# endif
