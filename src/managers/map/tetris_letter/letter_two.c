/*
** EPITECH PROJECT, 2018
** letter_2
** File description:
** tetris
*/

# include "tetris.h"

void letter_two(void)
{
	attron(COLOR_PAIR(2));
	mvprintw(1, 7, "* * *");
	mvprintw(2, 7, "*");
	mvprintw(3, 7, "* *");
	mvprintw(4, 7, "*");
	mvprintw(5, 7, "* * *");
	attroff(COLOR_PAIR(2));
}
