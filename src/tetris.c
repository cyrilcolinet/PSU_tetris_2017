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
	int n = -1;

	if (err != 0)
		return (err);
	for (int i = 0; i < ac; i++) {
		param->debug = 0;
		if (av[i][0] == '-' && av[i][1] == 'D'
		    && av[i][2] == '\0') {
			debug_mode(param);
			break;
		}
	}
	if (param->debug == 1) {
		/* while (n == -1) { */
		/* 	if (getch()) */
		/* 		n = 2; */
		/* } */
	}
//	display_game(param);
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
