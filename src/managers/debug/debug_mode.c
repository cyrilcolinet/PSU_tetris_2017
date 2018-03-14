/*
** EPITECH PROJECT, 2018
** debug_mode
** File description:
** tetris
*/

#include "tetris.h"

void debug_mode(main_t *param)
{
	my_putstr("*** DEBUG MODE ***\n");
	my_putstr("Key Left : ");
	my_putstr("");
	my_putstr("\nKey Right : ");
	my_putstr("");
	my_putstr("\nKey Turn : ");
	my_putstr("");
	my_putstr("\nKey Drop : ");
	my_putstr("");
	my_putstr("\nKey Quit : ");
	my_putstr("");
	my_putstr("\nKey Pause : ");
	my_putstr("");
	my_putstr("\nNext : ");
	my_putstr("Yes");
	my_putstr("No");
	my_putstr("\nLevel : ");
	my_put_nbr(1);
	my_putstr("\nSize : ");
	my_put_nbr(1);
	my_putstr("*");
	my_put_nbr(1);
	my_putstr("\nTetriminos : ");
	my_put_nbr(1);
	my_putchar('\n');

	tetriminos_t *tmp = param->tetri;

	while (tmp->next != NULL) {
		if (tmp->next->id >= 0) {
			my_putstr("Tetriminos : Name ");
			my_putstr(tmp->next->name);
			my_putstr(" : ");
			if (tmp->next->invalid == 0) {
				my_putstr("Size ");
				my_put_nbr(tmp->next->width);
				my_putstr("*");
				my_put_nbr(tmp->next->height);
				my_putstr(" : Color ");
				my_put_nbr(tmp->next->color);
				my_putstr(" :\n");
				for (int i = 0; tmp->next->form[i] != NULL; i++) {
					my_putstr(tmp->next->form[i]);
					my_putstr("\n");
				}
			} else
				my_putstr("Error\n");
		}
		tmp = tmp->next;
	}
	param->debug = 1;
}
