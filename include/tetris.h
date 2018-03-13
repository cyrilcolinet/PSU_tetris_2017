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

# include "my.h"
# include "structs.h"

typedef struct stat stat_t;
typedef struct dirent dir_t;

// tetris.c
int 	tetris_main(int ac, char **av);

//error_management
int 	check_err(int ac, char **av);

// utils/struct_utils.c
void 	free_all(main_t *main);
main_t 	*configure(void);

// utils/get_next_line.c
char 	*get_next_line(int fdesc);

//map_management
void 	display_game(main_t *param);
void 	display_map(void);
void 	display_score(void);
void	display_next_tetri(void);

//create_tetris_title
void 	create_tetris_title(void);
void 	letter_1(void);
void 	letter_2(void);
void 	letter_3(void);
void 	letter_4(void);
void 	letter_5(void);
void 	letter_6(void);

// managers/directory_reader.c
void 	fill_files(files_t *files, char *path, char *name);
int 	throw_directory(files_t *files, dir_t *dent);
files_t *get_all_files(void);
int 	load_all_tetriminos(main_t *param);
int 	config_tetriminos(main_t *param);

// managers/tetrimiis/parse_file.c
char 	*get_first_line(char *file);
void 	set_first_values(tetriminos_t *tmp, char *path);
char 	*parse_filename(char *file);
char 	**get_tetrimino_form(char *file, int height);

// managers/tetriminos/load_tetriminos.c


# endif
