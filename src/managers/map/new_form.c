/*
** EPITECH PROJECT, 2018
** new_form
** File description:
** tetris
*/

# include "tetris.h"

map_t *add_new_form_map(map_t *tmp)
{
	tmp->stop = 0;
	tmp = tmp->next;
	tmp->stop = 1;
	tmp->pos_x = 35;
	tmp->pos_y = 2;
	return (tmp);
}
