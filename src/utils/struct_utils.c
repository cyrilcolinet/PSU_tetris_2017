/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** struct_utils functions
*/

# include "tetris.h"

void free_all(main_t *param)
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
	for (int i = 0; param->current[i] != NULL; i++)
		free(param->current[i]);
	free(param->current);
	for (int i = 0; param->next[i] != NULL; i++)
		free(param->next[i]);
	free(param->next);
	free(param);
}

main_t *configure(void)
{
	main_t *param = malloc(sizeof(main_t));

	if (param == NULL)
		return (NULL);

	param->tetri = malloc(sizeof(tetriminos_t));
	if (param->tetri == NULL)
		return (NULL);

	param->tetri->id = -1;
	param->tetri->name = NULL;
	param->tetri->form = NULL;
	param->tetri->path = NULL;
	param->tetri->next = NULL;
	return (param);
}
