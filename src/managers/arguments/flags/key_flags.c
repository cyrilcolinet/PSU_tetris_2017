/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** key_falgs functions
*/

# include "tetris.h"

void manage_level_flag(main_t *param)
{
	int level = 0;

	if (!my_str_isnum(optarg)) {
		write(2, optarg, my_strlen(optarg));
		write(2, " : is not a number.\n", 20);
		return;
	}

	level = my_atoi(optarg);
	param->config->level = level;
}
