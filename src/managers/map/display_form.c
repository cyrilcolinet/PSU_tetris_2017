/*
** EPITECH PROJECT, 2018
** display_form
** File description:
** tetris
*/

#include "tetris.h"

static int print_space(map_t *tmp, int i, int j, int nb)
{
	if (tmp->form[i][j + 1] != '\0') {
		mvprintw(tmp->pos_y + i,
			 tmp->pos_x + nb, "%c", ' ');
		nb++;
	}
	return (nb);
}

void display_form(map_t *tmp)
{
	int nb = 0;

	attron(COLOR_PAIR(tmp->color));
	for (int i = 0; tmp->form[i] != NULL; i++) {
		nb = 0;
		for (int j = 0; tmp->form[i][j] != '\0'; j++) {
			mvprintw(tmp->pos_y + i,
				tmp->pos_x + nb, "%c", tmp->form[i][j]);
			nb++;
			nb = print_space(tmp, i, j ,nb);
		}
	}
	attroff(COLOR_PAIR(tmp->color));
}
