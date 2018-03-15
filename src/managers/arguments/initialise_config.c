/*
** EPITECH PROJECT, 2018
** initialise_config
** File description:
** tetris
*/

#include "tetris.h"

void initialise_config(main_t *param)
{
	param->config->kl = 'a';
	param->config->kr = 'z';
	param->config->kt = 't';
	param->config->kd = 'd';
	param->config->kq = 'q';
	param->config->kp = 'p';
	param->config->next = 1;
	param->config->level = 1;
	param->config->size_w = 10;
	param->config->size_h = 20;
	param->config->nb_tetri = 0;
}
