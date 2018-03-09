/*
** EPITECH PROJECT, 2018
** letter_6
** File description:
** tetris
*/

#include "tetris.h"

void letter_6(void)
{
	attron(COLOR_PAIR(6));
	mvprintw(1, 27, "* * *");
	mvprintw(2, 27, "*");
	mvprintw(3, 27, "* * *");
	mvprintw(4, 27, "    *");
	mvprintw(5, 27, "* * *");
	attroff(COLOR_PAIR(6));
}
