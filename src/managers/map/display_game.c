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

	tmp = malloc(sizeof(map_t));
	tmp = create_random_tetri(param);
        tmp->next = create_random_tetri(param);
        tmp->pos_x = 35;
        tmp->pos_y = 2;

	initscr();
	noecho();
	curs_set(FALSE);
	ini_color();

	while (n != param->config->kq) {
		clear();
		display_form(tmp);
		create_tetris_title();
		display_map(param);
		display_score(param);
		if (param->config->next)
			display_next_tetri(param, tmp->next);
		n = getch();
		deplacement(param, tmp, n);
		if (tmp->pos_x == 45) {
			tmp = tmp->next;
			tmp->pos_x = 35;
			tmp->pos_y = 2;
			tmp->next = create_random_tetri(param);
		}
//		add_new_form_map(param, tmp);
		refresh();
	}
	endwin();
}
