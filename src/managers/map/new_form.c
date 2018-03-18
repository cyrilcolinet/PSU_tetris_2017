/*
** EPITECH PROJECT, 2018
** new_form
** File description:
** tetris
*/

# include "tetris.h"

void add_new_form_map(main_t *param)
{
	map_t *tmp = param->map;

	while (tmp->next->stop == 0)
		tmp = tmp->next;
	tmp = tmp->next;
	tmp->stop = 0;
	tmp->next->stop = 1;
	tmp->next->pos_x = 35;
	tmp->next->pos_y = 2;
	tmp->next->next = create_random_tetri(param);
	tmp->next->next->stop = 2;
	tmp->next->next->next = NULL;
}
