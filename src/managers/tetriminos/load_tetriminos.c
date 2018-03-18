/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** load_tetriminos functions
*/

# include "tetris.h"

void setup_tetrimino(dir_t *dirent, main_t *param)
{
	char *path = NULL;
	stat_t info;
	int st = 0;

	if (!my_strendswith(dirent->d_name, ".tetrimino"))
		return;

	path = my_strjoin(TETRIMINOS_DIR, dirent->d_name);
	st = stat(path, &info);

	if (st < 0)
		return;

	fill_struct(param, path, dirent->d_name);
}

int get_files(main_t *param)
{
	DIR *dir = opendir(TETRIMINOS_DIR);
	dir_t *dirent = NULL;

	if (dir == NULL) {
		write(2, "Error while openning folder\n", 28);
		return (84);
	}

	while ((dirent = readdir(dir)))
		setup_tetrimino(dirent, param);

	closedir(dir);
	return (0);
}

int config_tetriminos(main_t *param)
{
	stat_t info;
	int st = stat(TETRIMINOS_DIR, &info);

	if (st < 0) {
		write(2, "Stat error. Abord.\n", 19);
		return (84);
	} else {
		if (!S_ISDIR(info.st_mode)) {
			write(2, TETRIMINOS_DIR, my_strlen(TETRIMINOS_DIR));
			write(2, " : is not a directory.\n", 23);
			return (84);
		}

		st = get_files(param);
	}
	return (st);
}

void free_tetriminos(main_t *param)
{
	tetriminos_t *tmp = NULL;

	while (param->tetri != NULL) {
		tmp = param->tetri;
		param->tetri = param->tetri->next;
		my_freetab(tmp->form);
		free(tmp->name);
		free(tmp->path);
		free(tmp);
	}
}
