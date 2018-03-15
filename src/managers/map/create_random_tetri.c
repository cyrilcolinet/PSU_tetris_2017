/*
** EPITECH PROJECT, 2018
** create_random_tetri
** File description:
** tetris
*/

#include "tetris.h"

static char **copie_form(char **str, char **tmp)
{
	int len = 0;

	for (int i = 0; tmp[i] != NULL; i++)
		len++;
	str = malloc(sizeof(char *) * (len + 1));
	str[len] = NULL;
	for (int i = 0; tmp[i] != NULL; i++) {
		len = 0;
		for (int j = 0; tmp[i][j] != '\0'; j++) {
			len++;
		}
		str[i] = malloc(sizeof(char) * (len + 1));
		str[i][len] = '\0';
	}
	for (int i = 0; tmp[i] != NULL; i++) {
		str[i] = my_strcpy(str[i], tmp[i]);
	}
	return (str);
}

map_t *create_random_tetri(main_t *param)
{
	tetriminos_t *tmp;
	int abc;
	int x = 1;
	map_t *new = malloc(sizeof(map_t));

	while (x == 1) {
		tmp = param->tetri;
		tmp = tmp->next;
		srand(time(NULL));
		for (int i = 0; i < 10; i++)
			abc = rand() % param->config->nb_tetri;
		while (tmp->id != abc) {
			tmp = tmp->next;
		}
		if (tmp->invalid == 0)
			x = 2;
	}
	new->color = tmp->color;
	new->form = copie_form(new->form, tmp->form);
	return (new);
}
