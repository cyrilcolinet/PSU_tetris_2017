/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** tetris functions
*/

# include "tetris.h"

int tetris(int ac, char **av, main_t *param)
{
	(void)ac, (void)av, (void)param;

	return (0);
}

int tetris_main(int ac, char **av)
{
	main_t *param;
	int err = check_err(ac, av);

	if (err == 1)
		return (84);
<<<<<<< HEAD
	display_map(m);
	free_all();
	return (0);
=======

	param = configure();
	if (param == NULL)
		return (84);

	err = tetris(ac, av, param);
	free_all(param);
	return (err);
>>>>>>> 7a5a660aca0e40138bceda078c47f83a6c6da0be
}
