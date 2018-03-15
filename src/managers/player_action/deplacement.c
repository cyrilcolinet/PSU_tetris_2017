/*
** EPITECH PROJECT, 2018
** deplacement
** File description:
** tetris
*/

#include "tetris.h"

static int get_len(main_t *param)
{
	int len = 0;
	int nb = 0;

	for (int i = 0; param->current[i] != NULL; i++) {
		len = 0;
		for (int j = 0; param->current[i][j] != '\0'; j++)
			len++;
		if (len > nb)
			nb = len;
	}
	nb = nb * 2 - 2;
	return (nb);
}

void deplacement(main_t *param, int n)
{
	char c;
	int nb = get_len(param);

	if (n == param->config->kr) {
		c = mvwinch(stdscr, param->pos_y, param->pos_x + nb + 2) & A_CHARTEXT;
		if (c != '|') {
			param->pos_x += 2;
		}
	}
	if (n == param->config->kl) {
		c = mvwinch(stdscr, param->pos_y, param->pos_x - 2) & A_CHARTEXT;
		if (c != '|') {
			param->pos_x -= 2;
		}
	}
}
