/*
** EPITECH PROJECT, 2018
** initialise_config
** File description:
** tetris
*/

#include "tetris.h"

void initialise_config(main_t *param)
{
	param->config->kl = 68;
	param->config->kr = 67;
	param->config->kt = 65;
	param->config->kd = 66;
	param->config->kq = 'q';
	param->config->kp = 32;
	param->config->next = 1;
	param->config->debug = 0;
	param->config->level = 1;
	param->config->size_w = 10;
	param->config->size_h = 20;
	param->config->nb_tetri = 0;
}
