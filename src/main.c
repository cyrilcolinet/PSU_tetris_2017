/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** Main file
*/

# include "tetris.h"

int main(int ac, char **av, char **env)
{
	int res = 84;

	if (*env == NULL)
		return (res);

	res = tetris_main(ac, av);
	return (res);
}
