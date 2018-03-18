/*
** EPITECH PROJECT, 2018
** fill_struct
** File description:
** tetris
*/

#include "tetris.h"

static tetriminos_t *fill_tetri(tetriminos_t *tmp, int id,
				char *path, char *file)
{
	tmp->id = id;
	tmp->name = parse_filename(file);
	tmp->path = path;
	tmp->form = NULL;
	return (tmp);
}

void fill_struct(main_t *param, char *path, char *file)
{
	tetriminos_t *tmp = param->tetri;
	int id = 1;
	int err;

	while (tmp->next != NULL) {
		tmp = tmp->next;
		id++;
	}
	tmp->next = malloc(sizeof(tetriminos_t));
	if (tmp->next == NULL)
		return;
	err = set_first_values(tmp->next, path);
	tmp->next = fill_tetri(tmp->next, id, path, file);
	tmp->next->next = NULL;
	if (err == 0) {
		tmp->next->form = get_tetrimino_form(path, tmp->next->height);
		tmp->next->invalid = 0;
	} else
		tmp->next->invalid = 1;
	param->config->nb_tetri++;
}
