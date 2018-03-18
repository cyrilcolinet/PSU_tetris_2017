/*
** EPITECH PROJECT, 2018
** letter_3
** File description:
** tetris
*/

# include "tetris.h"

void letter_three(void)
{
	attron(COLOR_PAIR(3));
	mvprintw(1, 13, "* * *");
	mvprintw(2, 15, "*");
	mvprintw(3, 15, "*");
	mvprintw(4, 15, "*");
	mvprintw(5, 15, "*");
	attroff(COLOR_PAIR(3));
}
