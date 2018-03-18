/*
** EPITECH PROJECT, 2018
** display_next_tetri
** File description:
** tetris
*/

# include "tetris.h"

void display_next_tetri_size_one(int n, int b)
{
	mvprintw(1 , n + 7, "\\");
	mvprintw(1 + b + 1 , n + 7, "/");
	for (int i = 1; i <= b; i++) {
		mvprintw(1 + i, n, "|");
		mvprintw(1 + i, n + 7, "|");
	}
	for (int i = 1; i < 7; i++) {
		mvprintw(1, n + i, "-");
		mvprintw(1 + b + 1, n + i, "-");
	}
}

static void display_bordure(int n, int a , int b)
{
	mvprintw(1 , n, "/");
	mvprintw(1 + b + 1, n, "\\");
	if (a > 1) {
		mvprintw(1 , n + a * 2 + 4, "\\");
		mvprintw(1 + b + 1 , n + a * 2 + 4, "/");
		for (int i = 1; i <= b; i++) {
			mvprintw(1 + i, n, "|");
			mvprintw(1 + i, n + a * 2 + 4, "|");
		}
		for (int i = 1; i < a * 2 + 4; i++) {
			mvprintw(1, n + i, "-");
			mvprintw(1 + b + 1, n + i, "-");
		}
	} else
		display_next_tetri_size_one(n, b);
}

void display_next_tetri(main_t *param, map_t *next)
{
	int n = 33 + param->config->size_w * 2 + 4;
	int len = 0;
	int a = 0;
	int b = 0;

	for (int i = 0; next->form[i] != NULL; i++) {
		b++;
		len = 0;
		for (int j = 0; next->form[i][j] != '\0'; j++){
			len++;
		}
		if (a < len)
			a = len;
	}
	display_bordure(n, a, b);
	mvprintw(1, n + 2, "next");
	next->pos_x = n + 2;
	next->pos_y = 2;
	display_form(next);
}
