/*
** EPITECH PROJECT, 2018
** debug_mode
** File description:
** tetris
*/

#include "tetris.h"

static void affichage_key(main_t *param)
{
	my_putstr("Key Left : ");
	my_putchar(param->config->kl);
	my_putstr("\nKey Right : ");
	my_putchar(param->config->kr);
	my_putstr("\nKey Turn : ");
	my_putchar(param->config->kt);
	my_putstr("\nKey Drop : ");
	my_putchar(param->config->kd);
	my_putstr("\nKey Quit : ");
	my_putchar(param->config->kq);
	my_putstr("\nKey Pause : ");
	my_putchar(param->config->kp);
	my_putstr("\nNext : ");
	if (param->config->next)
		my_putstr("Yes");
	else
		my_putstr("No");
}

static void affichage_info_valid(tetriminos_t *tmp)
{
	my_putstr("Size ");
	my_put_nbr(tmp->height);
	my_putstr("*");
	my_put_nbr(tmp->width);
	my_putstr(" : Color ");
	my_put_nbr(tmp->color);
	my_putstr(" :\n");
	for (int i = 0; tmp->form[i] != NULL; i++) {
		my_putstr(tmp->form[i]);
		my_putstr("\n");
	}
}

static void affichage_tetrimino(main_t *param)
{
	tetriminos_t *tmp = param->tetri;

	while (tmp->next != NULL) {
		if (tmp->next->id >= 0) {
			my_putstr("Tetriminos : Name ");
			my_putstr(tmp->next->name);
			my_putstr(" : ");
			if (tmp->next->invalid == 0)
				affichage_info_valid(tmp->next);
			else
				my_putstr("Error\n");
		}
		tmp = tmp->next;
	}
}

void debug_mode(main_t *param)
{
	char *line = NULL;

	if (param->config->debug) {
		my_putstr("*** DEBUG MODE ***\n");
		affichage_key(param);
		my_putstr("\nLevel : ");
		my_put_nbr(param->config->level);
		my_putstr("\nSize : ");
		my_put_nbr(param->config->size_w);
		my_putstr("*");
		my_put_nbr(param->config->size_h);
		my_putstr("\nTetriminos : ");
		my_put_nbr(param->config->nb_tetri);
		my_putchar('\n');
		affichage_tetrimino(param);
		my_putstr("Press any key to start Tetris\n");
		line = get_next_line(0);
		free(line);
	}
}
