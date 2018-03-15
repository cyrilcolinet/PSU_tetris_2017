/*
** EPITECH PROJECT, 2018
** display_map
** File description:
** tetris
*/

#include "tetris.h"

void display_game(main_t *param)
{
	int n = 1;

	param->pos.x = 35;
	param->pos.y = 2;

	initscr();
	keypad(stdscr, TRUE);
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

	create_current(param);
	create_next(param);

	while (n != param->config->kq) {
		clear();
		display_form(param->current, param->pos.x, param->pos.y);
		create_tetris_title();
		display_map(param);
		display_score(param);
		if (!param->config->next)
			display_next_tetri(param);
		n = getch();
		deplacement(param, n);
		refresh();
	}
	endwin();
}
