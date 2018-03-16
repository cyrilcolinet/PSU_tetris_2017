/*
** EPITECH PROJECT, 2018
** create_random_tetri
** File description:
** tetris
*/

# include "tetris.h"

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
	tetriminos_t *tmp = param->tetri;
	map_t *new = malloc(sizeof(map_t));
	int nb = 0;
	bool set = false;

	srand(time(NULL));
	while (nb <= 0 || nb > 10)
		nb = (rand() + 1) % (param->config->nb_tetri + 1);
	while (!set) {
		while (tmp->next != NULL) {
			if (tmp->next->id == nb
			&& tmp->next->invalid == 0) {
				set = true;
				break;
			} else if (tmp->next->id == nb
				&& tmp->next->invalid == 1) {
				nb = (rand() + 1) %
					(param->config->nb_tetri + 1);
				tmp = param->tetri;
				break;
			}
			tmp = tmp->next;
		}
	}
	new->color = tmp->next->color;
	new->form = copie_form(new->form, tmp->next->form);
	return (new);
}
