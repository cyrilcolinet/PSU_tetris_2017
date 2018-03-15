/*
** EPITECH PROJECT, 2018
** new_form
** File description:
** tetris
*/

#include "tetris.h"

void add_new_form_map(main_t *param, map_t *tmp)
{
	if (tmp->pos_x == 45) {
		tmp = tmp->next;
		tmp->pos_x = 35;
		tmp->pos_y = 35;
		tmp->next = create_random_tetri(param);
	}
}
