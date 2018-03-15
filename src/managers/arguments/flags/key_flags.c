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

char **map_change_error(int count)
{
	char **arr = NULL;

	if (count != 1) {
		write(2, optarg, my_strlen(optarg));
		write(2, " : invalid map size.\n", 21);
		my_freetab(arr);
		return (NULL);
	}
	arr = my_strtok(optarg, ',');
	if (arr[1] == NULL) {
		write(2, optarg, my_strlen(optarg));
		write(2, " : invalid map size.\n", 21);
		return (NULL);
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
	arr = map_change_error(count);
	if (!arr)
		return;
	for (i = 0; arr[i]; i++)
		if (!my_str_isnum(arr[i])) {
			write(2, optarg, my_strlen(optarg));
			write(2, " : invalid map size.\n", 21);
			my_freetab(arr);
			return;
		}
	param->config->size_h = my_atoi(arr[0]);
	param->config->size_w = my_atoi(arr[1]);
	my_freetab(arr);
}

void change_key(int res, main_t *param)
{
	if (my_strlen(optarg) != 1) {
		write(2, optarg, my_strlen(optarg));
		write(2, "Invalid key character.\n", 23);
	} else {
		switch (res) {
			case 'l': param->config->kl = optarg[0];
			break;
			case 'r': param->config->kr = optarg[0];
			break;
			case 't': param->config->kt = optarg[0];
			break;
			case 'd': param->config->kd = optarg[0];
			break;
			case 'q': param->config->kq = optarg[0];
			break;
			case 'p': param->config->kp = optarg[0];
			default:
			break;
		}
	}
}
