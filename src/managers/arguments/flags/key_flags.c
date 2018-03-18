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
		free_all(param);
		exit(84);
	}

	level = my_atoi(optarg);
	param->config->level = level;
}

char **map_change_error(int count, main_t *param)
{
	char **arr = NULL;

	if (count != 1) {
		write(2, "Invalid map size.\n", 18);
		my_freetab(arr);
		free_all(param);
		exit(84);
	}
	arr = my_strtok(optarg, ',');
	if (arr[1] == NULL) {
		write(2, "Invalid map size.\n", 18);
		my_freetab(arr);
		free_all(param);
		exit(84);
	}

	return (arr);
}

void change_map_size(main_t *param)
{
	char **arr = NULL;
	int count = 0;
	int i = 0;

	for (i = 0; optarg[i]; i++)
		if (optarg[i] == ',')
			count++;
	arr = map_change_error(count, param);
	if (!arr)
		return;
	for (i = 0; arr[i]; i++)
		if (!my_str_isnum(arr[i])) {
			write(2, "Invalid map size.\n", 18);
			my_freetab(arr);
			free_all(param);
			exit(84);
		}
	param->config->size_h = my_atoi(arr[0]);
	param->config->size_w = my_atoi(arr[1]);
	my_freetab(arr);
}

void key_error(char multi, main_t *param)
{
	if (multi == 0 && my_strlen(optarg) != 1) {
		write(2, "Invalid key character.\n", 23);
		free_all(param);
		exit(84);
	}
}

void change_key(int res, main_t *param)
{
	char multi = check_multitouch();

	key_error(multi, param);
	multi = ((multi == 0) ? *optarg : multi);
	switch (res) {
		case 'l': param->config->k_left = config_key(multi);
		break;
		case 'r': param->config->k_right = config_key(multi);
		break;
		case 't': param->config->k_turn = config_key(multi);
		break;
		case 'd': param->config->k_drop = config_key(multi);
		break;
		case 'q': param->config->k_quit = config_key(multi);
		break;
		case 'p': param->config->k_pause = config_key(multi);
		default:
		break;
	}
}
