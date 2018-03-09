/*
** EPITECH PROJECT, 2018
** display_score
** File description:
** tetris
*/

#include "tetris.h"

static void diplay_value_score()
{}

void display_score(void)
{
	mvprintw(8, 1, "/");
	mvprintw(8, 28, "\\");
	mvprintw(17, 1, "\\");
	mvprintw(17, 28, "/");
	for (int i = 1; i < 27; i++) {
		mvprintw(8, 1 + i, "-");
		mvprintw(17, 1 + i, "-");
	}
	for (int i = 1; i < 9; i++) {
		mvprintw(8 + i, 28, "|");
		mvprintw(8 + i, 1, "|");
	}
	mvprintw( 10, 3, "High Score");
	mvprintw( 11, 3, "Score");
	mvprintw( 13, 3, "Lines");
	mvprintw( 14, 3, "Level");
	mvprintw( 16, 3, "Timer");
	display_value_score();
}
