/*
** EPITECH PROJECT, 2018
** display_score
** File description:
** tetris
*/

#include "tetris.h"

static int nb_length(int nb)
{
	int n = 0;

	while (nb / 10 > 0) {
		nb = nb / 10;
		n++;
	}
	return (n);
}

static void display_value_score()
{
	int nb = nb_length(100);
	mvprintw( 10, 26 - nb, "100");
	nb = nb_length(1);
	mvprintw( 11, 26 - nb, "1");
	nb = nb_length(4957385);
	mvprintw( 13, 26 - nb, "4957385");
	nb = nb_length(2487);
	mvprintw( 14, 26 - nb, "2487");
	nb = nb_length(0);
	/* if ( n < 10) { */
	/* 	nb++;		 */
	/* 	mvprintw( 16, 26 - nb, "01"); */
	/* } else */
		mvprintw( 16, 26 - nb, "0");
}

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
