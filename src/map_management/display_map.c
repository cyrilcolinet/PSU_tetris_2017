/*
** EPITECH PROJECT, 2018
** display_map
** File description:
** tetris
*/

#include "tetris.h"

void display_map(void)
{
	int x = 20;
	int y = 10;

	mvprintw(1, 33, "+");
	mvprintw(1, 33 + y * 2 + 2, "+");
	mvprintw(1 + x, 33, "+");
	mvprintw(1 + x, 33 + y * 2 + 2, "+");
	for (int i = 1; i <= y * 2 + 1; i++) {
		mvprintw(1, 33 + i, "-");
		mvprintw(1 + x, 33 + i, "-");
	}
	for (int i = 1; i < x; i++) {
		mvprintw(1 + i, 33, "|");
		mvprintw(1 + i, 33 + y * 2 + 2, "|");
	}
	/* char c = (char)mvwinch(stdscr, 3, 33) & A_CHARTEXT; */
	/* mvprintw(30, 3, &c); */
}
