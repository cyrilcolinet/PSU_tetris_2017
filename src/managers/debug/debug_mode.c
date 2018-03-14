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
	my_putchar(param->config.kl);
	my_putstr("\nKey Right : ");
	my_putchar(param->config.kr);
	my_putstr("\nKey Turn : ");
	my_putchar(param->config.kt);
	my_putstr("\nKey Drop : ");
	my_putchar(param->config.kd);
	my_putstr("\nKey Quit : ");
	my_putchar(param->config.kq);
	my_putstr("\nKey Pause : ");
	my_putchar(param->config.kp);
	my_putstr("\nNext : ");
	if (param->config.next)
		my_putstr("Yes");
	else
		my_putstr("No");
	my_putstr("\nLevel : ");
	my_put_nbr(param->config.level);
	my_putstr("\nSize : ");
	my_put_nbr(param->config.size_w);
	my_putstr("*");
	my_put_nbr(param->config.size_h);
	my_putstr("\nTetriminos : ");
	my_put_nbr(param->config.nb_tetri);
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
	my_putstr("Press any key to start Tetris\n");
	param->debug = 1;
}
