/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** directory_reader functions
*/

# include "tetris.h"

int load_all_tetriminos(stat_t info, main_t *param)
{
	return (0);
}

int config_tetriminos(main_t *param)
{
	stat_t info;

	if (stat("./tetriminos/", &info) < 0) {
		write(2, strerror(errno), my_strlen(strerror(errno)));
		return (84);
	} else if (!S_ISDIR(info.st_mode)) {
		write(2, "Error: './tetriminos/' isn't a directory.\n", 42);
		return (84);
	}

	return (load_all_tetriminos(info, param));
}
