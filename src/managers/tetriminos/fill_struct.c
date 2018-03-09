/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** fill_struct functions
*/


# include "tetris.h"

void get_start_values(char *path, tetriminos_t *tetri)
{
	int fd = open(path, O_RDONLY);
	char *val = NULL;
	char **res = NULL;

	if (fd < 0)
		return;

	val = get_next_line(fd);
	close(fd);

	if (val != NULL) {
		res = my_strtok(val, ' ');
		tetri->height = my_atoi(res[0]);
		tetri->width = my_atoi(res[1]);
		tetri->color = my_atoi(res[2]);
		my_freetab(res);
	}
	free(val);
}

char **get_form(char *path, tetriminos_t *tetri)
{
	char **arr = malloc(sizeof(char) * (tetri->height + 1));
	int i = 0;
	int fd = open(path, O_RDONLY);

	if (arr == NULL | fd < 0)
		return (NULL);

	for (i = 0; i < tetri->height + 1; i++) {
		arr[i] = get_next_line(fd);
		if (arr[i] == NULL)
			return (NULL);
	}

	arr[(tetri->height + 1)] = NULL;
	close(fd);
	return (arr);
}

void fill_tetriminos(main_t *param, files_t *file)
{
	tetriminos_t *tmp = NULL;

	if (param->tetri == NULL || file == NULL)
		return;

	tmp = param->tetri;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = malloc(sizeof(tetriminos_t));
	if (tmp->next == NULL)
		return;

	get_start_values(file->path, tmp->next);
	tmp->next->id = file->id;
	tmp->next->name = file->name;
	tmp->next->path = file->path;
	tmp->next->form = get_form(file->path, tmp->next);
	tmp->next->next = NULL;
}
