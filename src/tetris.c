/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** tetris functions
*/

# include "tetris.h"

static void free_all(void)
{
}

int tetris_main(int ac, char **av)
{
	int err;

	err = check_err(ac, av);
	if (err == 1)
		return (84);
	free_all();
	return (0);
}
