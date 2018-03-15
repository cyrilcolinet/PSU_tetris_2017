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
<<<<<<< HEAD
	if (param->next != NULL && param->current != NULL) {
		for (int i = 0; param->current[i] != NULL; i++)
			free(param->current[i]);
		free(param->current);
		for (int i = 0; param->next[i] != NULL; i++)
			free(param->next[i]);
		free(param->next);
	}
=======

	my_freetab(param->current);
	my_freetab(param->next);
	free(param->stats);
	free(param->config);
>>>>>>> b99759af8c4b17bcd83df55d05223d6e47ecf106
	free(param);
}

void configure_tetri_struct(main_t *param)
{
	param->tetri->id = -1;
	param->tetri->name = NULL;
	param->tetri->form = NULL;
	param->tetri->path = NULL;
	param->tetri->next = NULL;
}

void configure_stats_struct(main_t *param)
{
	param->stats->level = 1;
	param->stats->score = 0;
	param->stats->high_score = 0;
	param->stats->lines = 0;
	param->stats->timer = 0;
}

main_t *configure(void)
{
	main_t *param = malloc(sizeof(main_t));

	if (param == NULL)
		return (NULL);
	param->tetri = malloc(sizeof(tetriminos_t));
	param->config = malloc(sizeof(config_t));
	param->stats = malloc(sizeof(stats_t));
	if (!param->tetri || !param->config || !param->stats)
		return (NULL);
	initialise_config(param);
	configure_tetri_struct(param);
	configure_stats_struct(param);
	param->current = NULL;
	param->next = NULL;
	return (param);
}
