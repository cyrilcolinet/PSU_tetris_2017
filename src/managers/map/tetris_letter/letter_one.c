/*
** EPITECH PROJECT, 2018
** letter_1
** File description:
** tetris
*/

# include "tetris.h"

void letter_one(void)
{
	attron(COLOR_PAIR(1));
	mvprintw(1, 1, "* * *");
	mvprintw(2, 3, "*");
	mvprintw(3, 3, "*");
	mvprintw(4, 3, "*");
	mvprintw(5, 3, "*");
	attroff(COLOR_PAIR(1));
}
