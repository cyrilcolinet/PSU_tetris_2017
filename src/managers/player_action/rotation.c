/*
** EPITECH PROJECT, 2018
** rotation
** File description:
** tetris
*/

#include "tetris.h"

static char **copie_and_rotate(char **new, char **form, int i, int j)
{
	int a = i;
	int b = j - 1;

	for (int e = 0; e < i; e++)
		for (int d = 0; d < j; d++)
			new[e][d] = ' ';
	for (int k = 0; form[k] != NULL; k++) {
		for (int l = 0; form[k][l] != '\0'; l++) {
			new[a - i][b] = form[k][l];
			i--;
		}
		i = a;
		b--;
	}
	return (new);
}

static int get_len(char **form)
{
	int len = 0;
	int nb = 0;

	for (int i = 0; form[i] != NULL; i++) {
		len = 0;
		for (int j = 0; form[i][j] != '\0'; j++)
			len++;
		if (len > nb)
			nb = len;
	}
	return (nb);
}

static char **malloc_new(char **new, char **form, int len, int nb)
{
	for (int i = 0; i < len; i++) {
		new[i] = malloc(sizeof(char) * (nb + 1));
		new[i][nb] = '\0';
	}
	new = copie_and_rotate(new, form, len, nb);
	return (new);
}

void rotation(main_t *param, int n, map_t *tmp)
{
	int len;
	int nb = 0;
	char **new;

	if (n == param->config->k_turn.c) {
		len = get_len(tmp->form);
		new = malloc(sizeof(char *) * (len + 1));
		new[len] = NULL;
		for (int i = 0; tmp->form[i] != NULL; i++)
			nb++;
		new = malloc_new(new, tmp->form, len , nb);
		my_freetab(tmp->form);
		tmp->form = new;
		if (len < nb)
			if ((tmp->pos_x + nb + nb - 2)
			>= (35 + param->config->size_w * 2))
				tmp->pos_x -= (nb - len) * 2;
	}
}
