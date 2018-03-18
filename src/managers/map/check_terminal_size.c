/*
** EPITECH PROJECT, 2018
** check_terminal_size.c
** File description:
** tetris
*/

#include "tetris.h"

int check_terminal_size(main_t *param)
{
	int max_x;
	int max_y;
	int n = 0;

	getmaxyx(stdscr, max_y, max_x);
	if(max_y < param->config->size_h  + 3
	   || max_x < (param->config->size_w * 2) * 2 + 35) {
		n = -12345;
	}
	return (n);
}
