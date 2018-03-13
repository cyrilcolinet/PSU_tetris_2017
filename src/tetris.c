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
//display_game(param);
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
	err = tetris(ac, av, param);
	free_all(param);
	return (err);
}
