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

	my_freetab(param->current);
	my_freetab(param->next);
	free(param->config);
	free(param);
}

main_t *configure(void)
{
	main_t *param = malloc(sizeof(main_t));

	if (param == NULL)
		return (NULL);

	param->tetri = malloc(sizeof(tetriminos_t));
	param->config = malloc(sizeof(config_t));
	if (!param->tetri || !param->config)
		return (NULL);

	param->tetri->id = -1;
	param->tetri->name = NULL;
	param->tetri->form = NULL;
	param->tetri->path = NULL;
	param->tetri->next = NULL;
	return (param);
}
