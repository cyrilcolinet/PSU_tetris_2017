/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** configure_args functions
*/

# include "tetris.h"

opt_t configure_args(void)
{
	opt_t options = {
			"help", no_argument, &display_help
	};
}
