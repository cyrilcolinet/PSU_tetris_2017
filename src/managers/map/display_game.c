/*
** EPITECH PROJECT, 2018
** display_map
** File description:
** tetris
*/

#include "tetris.h"

void ini_color(void)
{
	use_default_colors();
	start_color();
	init_pair(1, COLOR_RED, -1);
	init_pair(2, COLOR_GREEN, -1);
	init_pair(3, COLOR_YELLOW, -1);
	init_pair(4, COLOR_BLUE, -1);
	init_pair(5, COLOR_MAGENTA, -1);
	init_pair(6, COLOR_CYAN, -1);
}

void display_game(main_t *param)
{
	int n = 1;
	map_t *tmp = param->map;

	tmp->next = create_random_tetri(param);
	tmp->next->next = create_random_tetri(param);
	tmp->next->next->next = NULL;
	tmp->next->stop = 1;
	tmp->next->next->stop = 2;
	tmp->next->pos_x = 35;
	tmp->next->pos_y = 2;

	initscr();
	noecho();
	curs_set(FALSE);
	ini_color();

	while (n != param->config->kq) {
		clear();
		create_tetris_title();
		display_map(param);
		display_score(param);
		display_form(tmp);
		if (param->config->next)
			display_next_tetri(param, tmp->next->next);
		n = getch();
		deplacement(param, tmp, n);
		if (n == 'c') {
			tmp->next = add_new_form_map(tmp->next);
			tmp->next->next = create_random_tetri(param);
			tmp->next->stop = 2;
			tmp->next->next->next = NULL;
		}
		refresh();
	}
	endwin();
}
