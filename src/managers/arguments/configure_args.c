/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** configure_args functions
*/

# include "tetris.h"

opt_t configure_args(void)
{
	opt_t options[] = {
			{ "level", required_argument, NULL, 1 },
			{ "key-left", required_argument, NULL, 2 },
			{ "key-rigth", required_argument, NULL, 3 },
			{ "key-turn", required_argument, NULL, 4 },
			{ "key-drop", required_argument, NULL, 5 },
			{ "key-quit", required_argument, NULL, 6 },
			{ "key-pause", required_argument, NULL, 7 },
			{ "map-size", required_argument, NULL, 8 },
			{ "without-next", no_argument, NULL, 9 },
			{ "debug", no_argument, NULL, 10 },
			{ "help", no_argument, NULL, 11 },
			{ 0, 0, 0,  }
	};

	return (options);
}

void arguments_manager(main_t *param)
{
	opt_t opt[] = configure_args();
	int res = 0;
	char *shortopt = "+L:l:r:t:d:q:p::wDh";

	while ((res = getopt_long(param->ac, param->av, shortopt, opt, NULL))) {
		printf("flag: %c && optarg: %s\n", res, optarg);
	}
}
