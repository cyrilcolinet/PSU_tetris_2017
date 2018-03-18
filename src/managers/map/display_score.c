/*
** EPITECH PROJECT, 2018
** display_score
** File description:
** tetris
*/

# include "tetris.h"

int nb_length(int nb)
{
	int n = 0;

	while (nb / 10 > 0) {
		nb = nb / 10;
		n++;
	}
	return (n);
}

void display_score_value(main_t *param)
{
	int nb = nb_length(param->stats->high_score);

	mvprintw( 10, 26 - nb, "%d", param->stats->high_score);
	nb = nb_length(param->stats->score);
	mvprintw( 11, 26 - nb, "%d", param->stats->score);
	nb = nb_length(param->stats->lines);
	mvprintw( 13, 26 - nb, "%d", param->stats->lines);
	nb = nb_length(param->stats->level);
	mvprintw( 14, 26 - nb, "%d", param->stats->level);
	nb = nb_length(param->stats->timer);
	if ( param->stats->timer < 10) {
		nb++;
		mvprintw( 16, 26 - nb, "0");
		mvprintw( 16, 26 - nb + 1, "%d", param->stats->timer);
	} else
		mvprintw( 16, 26 - nb, "%d", param->stats->timer);
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
	display_score_value(param);
}
