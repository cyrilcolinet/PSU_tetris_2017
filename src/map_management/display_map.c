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
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	while (n != 27) {
		clear();
		create_tetris_title();
		refresh();
		n = getch();
	}
	endwin();
}
