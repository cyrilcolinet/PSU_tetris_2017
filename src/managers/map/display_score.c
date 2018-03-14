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

static void display_value_score(main_t *param)
{
	int nb = nb_length(param->high_score);

	mvprintw( 10, 26 - nb, "%d", param->high_score);
	nb = nb_length(param->score);
	mvprintw( 11, 26 - nb, "%d", param->score);
	nb = nb_length(param->lines);
	mvprintw( 13, 26 - nb, "%d", param->lines);
	nb = nb_length(param->level);
	mvprintw( 14, 26 - nb, "%d", param->level);
	nb = nb_length(param->timer);
	if ( param->timer < 10) {
		nb++;
		mvprintw( 16, 26 - nb, "0");
		mvprintw( 16, 26 - nb + 1, "%d", param->timer);
	} else
		mvprintw( 16, 26 - nb, "%d", param->timer);
}

void display_score(main_t *param)
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
	display_value_score(param);
}
