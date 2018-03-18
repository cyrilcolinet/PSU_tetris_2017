/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** struct_utils functions
*/

# include "tetris.h"

void free_map(main_t *param)
{
	map_t *map = NULL;

	while (param->map != NULL) {
		map = param->map;
		param->map = param->map->next;
		my_freetab(map->form);
		free(map);
	}
}

void free_all(main_t *param)
{
	free_tetriminos(param);
	free_map(param);
	free_keymaps(param);

	free(param->stats);
	free(param->config);
	free(param);
}

void configure_tetri_struct(main_t *param)
{
	param->tetri->id = -1;
	param->tetri->name = NULL;
	param->tetri->form = NULL;
	param->tetri->path = NULL;
	param->tetri->next = NULL;
	param->map->form = NULL;
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
	param->map = malloc(sizeof(map_t));
	param->config = malloc(sizeof(config_t));
	param->stats = malloc(sizeof(stats_t));
	if (!param->tetri || !param->config
	|| !param->stats ||!param->map)
		return (NULL);
	initialise_config(param);
	configure_tetri_struct(param);
	configure_stats_struct(param);
	return (param);
}
