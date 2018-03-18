/*
** EPITECH PROJECT, 2018
** error_size_color
** File description:
** tetris
*/

#include "tetris.h"

int error_size_color(char *str)
{
	char **tmp;
	int nb;

	for (int i = 0; str[i] != '\0'; i++) {
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ') {
			return (1);
		}
	}
	tmp = my_strtok(str, ' ');
	nb = my_atoi(tmp[2]);
	if (nb < 1 || nb > 6) {
		my_freetab(tmp);
		return (1);
	}
	my_freetab(tmp);
	return (0);
}
