/*
** EPITECH PROJECT, 2018
** error_form
** File description:
** tetris
*/

# include "tetris.h"

static tetriminos_t *check_invalid(tetriminos_t *tmp, int i, int j, int nb)
{
	if (nb == 1) {
		if (tmp->color == 0 || tmp->color > 6)
			tmp->invalid = 1;
	} else if (nb == 2){
		if (tmp->form[i][j] != ' '
		&& tmp->form[i][j] != '*')
			tmp->invalid = 1;
	}
	return (tmp);
}

tetriminos_t *check_character(tetriminos_t *tmp, main_t *param)
{
	int len = 0;
	int width = 0;
	int height = 0;

	for (int i = 0; tmp->form[i] != NULL; i++) {
		height++;
		len = 0;
		for (int j = 0; tmp->form[i][j] != '\0' ; j++) {
			len++;
			tmp = check_invalid(tmp, i, j, 2);
		}
		if (width < len)
			width = len;
	}
	if (height >= param->config->size_h)
		tmp->invalid = 1;
	if (width >= param->config->size_w)
		tmp->invalid = 1;
	return (tmp);
}

void error_form(main_t *param)
{
	tetriminos_t *tmp = param->tetri;

	while (tmp->next != NULL) {
		if (tmp->next->invalid == 0) {
			tmp->next = check_invalid(tmp->next, 0, 0, 1);
			tmp->next = check_character(tmp->next, param);
		}
		tmp = tmp->next;
	}
}
