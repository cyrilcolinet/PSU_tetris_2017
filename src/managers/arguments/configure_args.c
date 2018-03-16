/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** configure_args functions
*/

# include "tetris.h"

void execute_action_on_flag(int res, main_t *param)
{
	switch (res) {
		case 'D': param->config->debug = 1;
		break;
		case 'L': manage_level_flag(param);
		break;
		case 'h': display_help(param);
		break;
		case 8: change_map_size(param);
		break;
		case '?':
			free_all(param);
			exit(84);
			break;
		default:
			if (res >= 0 && res <= 127 && optarg != NULL)
				change_key(res, param);
		break;
	}
}

void arguments_manager(main_t *param)
{
	int res = 0;
	char *shortopt = "+L:l:r:t:d:q:p:Dh";
	opt_t opt[] = {
		{ "without-next", no_argument, &param->config->next, 0 },
		{ "level", required_argument, NULL, 'L' },
		{ "key-left", required_argument, NULL, 'l' },
		{ "key-right", required_argument, NULL, 'r' },
		{ "key-turn", required_argument, NULL, 't' },
		{ "key-drop", required_argument, NULL, 'd' },
		{ "key-quit", required_argument, NULL, 'q' },
		{ "key-pause", required_argument, NULL, 'p' },
		{ "debug", no_argument, &param->config->debug, 1 },
		{ "help", no_argument, NULL, 'h' },
		{ "map-size", required_argument, NULL, 8 }
	};

	while (res >= 0) {
		res = getopt_long(param->ac, param->av, shortopt, opt, NULL);
		execute_action_on_flag(res, param);
	}
}
