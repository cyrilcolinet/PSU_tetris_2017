/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** tetris functions
*/

# include "tetris.h"

int tetris(int ac, char **av, main_t *param)
{
	int err = config_tetriminos(param);

	if (err != 0)
		return (err);

	/*tetriminos_t *tmp = param->tetri;

	while (tmp->next != NULL) {
	printf("h, w, c: %d %d %d\n", tmp->next->height, tmp->next->width, tmp->next->color);
	printf("name: %s\n", tmp->next->name);
	for (int i = 0; tmp->next->form[i]; i++)
		printf("form[%d]: %s\n", i, tmp->next->form[i]);
		tmp = tmp->next;
	}*/
	return (0);
}

int tetris_main(int ac, char **av)
{
	main_t *param;
	int err = check_err(ac, av);

	if (err == 1)
		return (84);
	param = configure();
	if (param == NULL)
		return (84);
	//display_game(param);
	err = tetris(ac, av, param);
	free_all(param);
	return (err);
}
