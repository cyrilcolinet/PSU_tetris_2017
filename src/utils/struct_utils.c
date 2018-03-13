/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** struct_utils functions
*/

# include "tetris.h"

void free_files(files_t *node)
{
	files_t *tmp = NULL;

	while (node != NULL) {
		tmp = node;
		node = node->next;
		free(tmp->name);
		free(tmp->path);
		free(tmp);
	}
}

void free_all(main_t *param)
{
	tetriminos_t *tmp = NULL;

	while (param->tetri != NULL) {
		tmp = param->tetri;
		param->tetri = param->tetri->next;
		free(tmp);
	}

	free(param);
}

main_t *configure(void)
{
	main_t *param = malloc(sizeof(main_t));

	if (param == NULL)
		return (NULL);

	param->tetri = malloc(sizeof(tetriminos_t));
	param->tetri->next = NULL;

	if (param->tetri == NULL)
		return (NULL);

	return (param);
}
