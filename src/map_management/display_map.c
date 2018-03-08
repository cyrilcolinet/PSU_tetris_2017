/*
** EPITECH PROJECT, 2018
** display_map
** File description:
** tetris
*/

#include "tetris.h"

void display_map(main_t *param)
{
	int n = 1;

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
	while (n != 27) {
		clear();
		create_tetris_title();
		refresh();
		n = getch();
	}
	endwin();
}
