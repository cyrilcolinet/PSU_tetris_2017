/*
** EPITECH PROJECT, 2018
** display_map
** File description:
** tetris
*/

#include "tetris.h"

static void ini_map(void)
{
	initscr();
	noecho();
	curs_set(FALSE);
	use_default_colors();
	start_color();
	init_pair(1, COLOR_RED, -1);
	init_pair(2, COLOR_GREEN, -1);
	init_pair(3, COLOR_YELLOW, -1);
	init_pair(4, COLOR_BLUE, -1);
	init_pair(5, COLOR_MAGENTA, -1);
	init_pair(6, COLOR_CYAN, -1);
}

static void display_all(main_t *param)
{
	clear();
	create_tetris_title();
	display_map(param);
	display_score(param);
}

void display_game(main_t *param)
{
	int n = 1;
	map_t *tmp = param->map;

	ini_map();
	tmp->next = create_random_tetri(param);
	tmp->next->next = create_random_tetri(param);
	tmp->next->next->next = NULL;
	tmp->next->stop = 1;
	tmp->next->next->stop = 2;
	tmp->next->pos_x = 35;
	tmp->next->pos_y = 2;
	while (n != param->config->k_quit.c) {
		display_all(param);
		display_form(tmp->next);
		if (param->config->next)
			display_next_tetri(param, tmp->next->next);
		n = getch();
		deplacement(param, tmp->next, n);
		rotation(param, n, tmp->next);
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
