/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** tetris functions
*/

# include "tetris.h"

static void param_info(main_t *param)
{
	param->level = param->config.level;   
	param->score = 0;
	param->high_score = 0;
	param->lines = 0;
	param->timer = 0;
}

int tetris(int ac, char **av, main_t *param)
{
	initialise_config(param);
	if (config_tetriminos(param) != 0)
		return (84);
	param_info(param);
	error_form(param);
	for (int i = 0; i < ac; i++) {
		param->debug = 0;
		if (av[i][0] == '-' && av[i][1] == 'D'
		&& av[i][2] == '\0') {
			debug_mode(param);
			break;
		}
	}
	if (param->debug == 1) {
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
	err = tetris(ac, av, param);
	free_all(param);
	return (err);
}
