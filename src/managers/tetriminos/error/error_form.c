/*
** EPITECH PROJECT, 2018
** error_form
** File description:
** tetris
*/

#include "tetris.h"

static void check_character(tetriminos_t *tmp, main_t *param)
{
	int len = 0;
	int width = 0;
	int height = 0;

	for (int i = 0; tmp->form[i] != NULL; i++) {
		height++;
		len = 0;
		for (int j = 0; tmp->form[i][j] != '\0' ; j++) {
			len++;
			if (tmp->form[i][j] != ' '
			&& tmp->form[i][j] != '*')
				tmp->invalid = 1;
		}
		if (width < len)
			width = len;
	}
	if (height >= param->config->size_h)
		tmp->invalid = 1;
	if (width >= param->config->size_w)
		tmp->invalid = 1;
}

void error_form(main_t *param)
{
	tetriminos_t *tmp = param->tetri;

	while (tmp->next != NULL) {
		if (tmp->next->invalid == 0) {
			if (tmp->next->color == 0 || tmp->next->color > 6)
				tmp->next->invalid = 1;
			check_character(tmp->next, param);
		}
		tmp = tmp->next;
	}
}
