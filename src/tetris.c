/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** tetris functions
*/

# include "tetris.h"

int tetris(int ac, char **av, main_t *param)
{
	initialise_config(param);
	if (config_tetriminos(param) != 0)
		return (84);
	arguments_manager(param); // temp
	error_form(param);
	debug_mode(param);
	if (param->config->debug == 1) {
	}
	display_game(param);
	return (0);
}

int tetris_main(int ac, char **av)
{
	main_t *param;
	int err;

	param = configure();
	if (param == NULL)
		return (84);
	param->ac = ac;
	param->av = av;
	err = tetris(ac, av, param);
	free_all(param);
	return (err);
}
