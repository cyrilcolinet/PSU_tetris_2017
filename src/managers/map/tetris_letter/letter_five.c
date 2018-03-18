/*
** EPITECH PROJECT, 2018
** letter_5
** File description:
** tetris
*/

# include "tetris.h"

void letter_five(void)
{
	attron(COLOR_PAIR(5));
	mvprintw(1, 25, "*");
	mvprintw(3, 25, "*");
	mvprintw(4, 25, "*");
	mvprintw(5, 25, "*");
	attroff(COLOR_PAIR(5));
}
