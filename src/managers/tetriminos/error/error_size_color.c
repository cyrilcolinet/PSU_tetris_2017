/*
** EPITECH PROJECT, 2018
** error_size_color
** File description:
** tetris
*/

#include "tetris.h"

int error_size_color(char *str)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ') {
			return (1);
		}
	}
	return (0);
}
