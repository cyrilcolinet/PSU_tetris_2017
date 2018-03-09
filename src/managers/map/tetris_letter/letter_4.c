/*
** EPITECH PROJECT, 2018
** letter_4
** File description:
** tetris
*/

#include "tetris.h"

void letter_4(void)
{
	attron(COLOR_PAIR(4));
	mvprintw(1, 19, "* * *");
	mvprintw(2, 19, "*   *");
	mvprintw(3, 19, "* *");
	mvprintw(4, 19, "*   *");
	mvprintw(5, 19, "*   *");
	attroff(COLOR_PAIR(4));
}
