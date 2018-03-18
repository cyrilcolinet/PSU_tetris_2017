/*
** EPITECH PROJECT, 2018
** create_random_tetri
** File description:
** tetris
*/

# include "tetris.h"

char **copy_form(char **str, char **tmp)
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

tetriminos_t *check_occurence(main_t *param, int nb)
{
	tetriminos_t *tmp = param->tetri;

	while (tmp->next != NULL) {
		if (tmp->next->id == nb && !tmp->next->invalid) {
			return (tmp->next);
		} else if (tmp->next->invalid == 1) {
			tmp = param->tetri;
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

map_t *create_random_tetri(main_t *param)
{
	tetriminos_t *val = NULL;
	map_t *new = malloc(sizeof(map_t));
	int nb = 0;

	srand(time(NULL));
	while (true) {
		nb = (rand() + 1) % (param->config->nb_tetri + 1);
		val = check_occurence(param, nb);
		if (val != NULL)
			break;
	}
	new->color = val->color;
	new->form = copy_form(new->form, val->form);
	return (new);
}
