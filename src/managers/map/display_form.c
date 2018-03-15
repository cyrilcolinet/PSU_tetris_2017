/*
** EPITECH PROJECT, 2018
** display_form
** File description:
** tetris
*/

#include "tetris.h"

void display_form(char **form, int pos_x, int pos_y)
{
	int nb = 0;

	for (int i = 0; form[i] != NULL; i++) {
		nb = 0;
		for (int j = 0; form[i][j] != '\0'; j++) {
			mvprintw(pos_y + i, pos_x + nb, "%c", form[i][j]);
			nb++;
			if (form[i][j + 1] != '\0') {
				mvprintw(pos_y + i, pos_x + nb, "%c", ' ');
				nb++;
			}
		}
	}
}
