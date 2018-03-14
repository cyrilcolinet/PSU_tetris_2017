/*
** EPITECH PROJECT, 2018
** display_next_tetri
** File description:
** tetris
*/

#include "tetris.h"

static void display_next_tetri_size_1(int n, int b)
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

void display_next_tetri(main_t *param, tetriminos_t *tmp)
{
	int n = 33 + param->config.size_w * 2 + 4;
	int a = tmp->width;
	int b = tmp->height;

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
		display_next_tetri_size_1(n, b);
	mvprintw(1, n + 2, "next");
	for (int i = 0; param->current[i] != NULL; i++)
		mvprintw(2 + i, n + 2, param->current[i]);
}
