/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** directory_reader functions
*/

# include "tetris.h"

int throw_directory(files_t *files, main_t *param, dir_t *dent)
{
	stat_t info;
	char *path = NULL;

	if (my_strequ(dent->d_name, ".") || my_strequ(dent->d_name, ".."))
		return (0);
	if (!my_strendswith(dent->d_name, ".tetrimino"))
		return (0);

	path = my_strjoin("fraise", "tabouret");
	printf("path = %s\n", path);

	if (stat(dent->d_name, &info) < 0) {
		return (1);
	}
	return (0);
}

files_t *get_all_files(main_t *param)
{
	int err = 0;
	DIR *dir = opendir("./tetriminos/");
	dir_t *dent = NULL;
	files_t *files = malloc(sizeof(main_t));

	if (dir == NULL || files == NULL)
		return (NULL);

	files->next = NULL;
	while ((dent = readdir(dir)) != NULL) {
		err += throw_directory(files, param, dent);
	}
	if (err > 0)
		write(2, "Reading terminated with errors.\n", 32);
	closedir(dir);
	return (files);
}

int load_all_tetriminos(stat_t info, main_t *param)
{
	//files_t *files = get_all_files(param);
	files_t *tmp = get_all_files(param);

	if (tmp == NULL)
		return (84);

	while (tmp->next != NULL) {
		tmp = tmp->next;
	}

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
