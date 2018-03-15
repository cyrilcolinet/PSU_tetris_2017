/*
** EPITECH PROJECT, 2018
** create_current_next
** File description:
** tetris
*/

#include "tetris.h"

static tetriminos_t *random_tetri(main_t *param)
{
	tetriminos_t *tmp;
	int abc;
	int x = 1;
	while (x == 1) {
		tmp = param->tetri;
		tmp = tmp->next;
		for (int i = 0; i < 10; i++)
			abc = random() % 6;
		while (tmp->id != abc) {
			tmp = tmp->next;
		}
		if (tmp->invalid == 0)
			x = 2;
	}
	return (tmp);
}

void create_next(main_t *param)
{
	tetriminos_t *tmp = random_tetri(param);
	int nb = 0;
	for (int i = 0; tmp->form[i] != NULL; i++)
		nb++;
	param->next = malloc(sizeof(char *) * (nb + 1));
	param->next[nb] = NULL;
	for (int i = 0; tmp->form[i] != NULL; i++) {
		nb = 0;
		for (int j = 0; tmp->form[i][j] != '\0'; j++)
			nb++;
		param->next[i] = malloc(sizeof(char) * (nb + 1));
		for (int j = 0; tmp->form[i][j] != '\0'; j++)
			param->next[i][j] = tmp->form[i][j];
		param->next[i][nb] = '\0';
	}
}

void create_current(main_t *param)
{
	tetriminos_t *tmp = random_tetri(param);
	int nb = 0;
	for (int i = 0; tmp->form[i] != NULL; i++)
		nb++;
	param->current = malloc(sizeof(char *) * (nb + 1));
	param->current[nb] = NULL;
	for (int i = 0; tmp->form[i] != NULL; i++) {
		nb = 0;
		for (int j = 0; tmp->form[i][j] != '\0'; j++)
			nb++;
		param->current[i] = malloc(sizeof(char) * (nb + 1));
		for (int j = 0; tmp->form[i][j] != '\0'; j++)
			param->current[i][j] = tmp->form[i][j];
		param->current[i][nb] = '\0';
	}
}
