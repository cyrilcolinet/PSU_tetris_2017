/*
** EPITECH PROJECT, 2018
** display_map
** File description:
** tetris
*/

# include "tetris.h"

static void display_previous_form(main_t *param)
{
	map_t *tmp = param->map;

	while (tmp->next->stop == 0) {
		display_form(tmp->next);
		tmp = tmp->next;
	}
}

void display_map(main_t *param)
{
	int x = param->config->size_w;
	int y = param->config->size_h;

	mvprintw(1, 33, "+");
	mvprintw(1, 33 + x * 2 + 2, "+");
	mvprintw(2 + y, 33, "+");
	mvprintw(2 + y, 33 + x * 2 + 2, "+");
	for (int i = 1; i <= x * 2 + 1; i++) {
		mvprintw(1, 33 + i, "-");
		mvprintw(2 + y, 33 + i, "-");
	}
	for (int i = 1; i < y + 1; i++) {
		mvprintw(1 + i, 33, "|");
		mvprintw(1 + i, 33 + x * 2 + 2, "|");
	}
	display_previous_form(param);
}
