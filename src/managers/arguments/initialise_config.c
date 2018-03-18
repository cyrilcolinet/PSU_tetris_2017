/*
** EPITECH PROJECT, 2018
** initialise_config
** File description:
** tetris
*/

# include "tetris.h"

void initialise_config(main_t *param)
{
	param->config->k_left = config_key(68);
	param->config->k_right = config_key(67);
	param->config->k_turn = config_key(65);
	param->config->k_drop = config_key(66);
	param->config->k_quit = config_key('q');
	param->config->k_pause = config_key(32);
	param->config->next = 1;
	param->config->debug = 0;
	param->config->level = 1;
	param->config->size_w = 10;
	param->config->size_h = 20;
	param->config->nb_tetri = 0;
}
