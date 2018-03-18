/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** map_struct_manager
*/

# include "tetris.h"

void new_fixed_tetrimino(main_t *param, int stop)
{
	map_t *tmp = param->map;
	int id = 0;

	while (tmp->next != NULL) {
		id++;
		tmp = tmp->next;
	}

	tmp->next = malloc(sizeof(map_t));
	if (!tmp->next)
		return;

	tmp->next = create_random_tetri(param);
	tmp->next->stop = stop;
	tmp->next->pos_x = 35;
	tmp->next->pos_y = 2;
}
