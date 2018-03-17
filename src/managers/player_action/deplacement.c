/*
** EPITECH PROJECT, 2018
** deplacement
** File description:
** tetris
*/

#include "tetris.h"

static int get_len(map_t *tmp)
{
	int len = 0;
	int nb = 0;

	for (int i = 0; tmp->form[i] != NULL; i++) {
		len = 0;
		for (int j = 0; tmp->form[i][j] != '\0'; j++)
			len++;
		if (len > nb)
			nb = len;
	}
	nb = nb * 2 - 2;
	return (nb);
}

void deplacement(main_t *param, map_t *tmp, int n)
{
	char c;
	int nb = get_len(tmp);

	if (n == param->config->k_right.c) {
		c = mvwinch(stdscr, tmp->pos_y, tmp->pos_x + nb + 2)
		& A_CHARTEXT;
		if (c != '|') {
			tmp->pos_x += 2;
		}
	}
	if (n == param->config->k_left.c) {
		c = mvwinch(stdscr, tmp->pos_y, tmp->pos_x - 2)
			& A_CHARTEXT;
		if (c != '|') {
			tmp->pos_x -= 2;
		}
	}
}
