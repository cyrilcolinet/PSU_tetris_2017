/*
** EPITECH PROJECT, 2018
** debug_mode
** File description:
** tetris
*/

# include "tetris.h"

void key_display(main_t *param)
{
	my_putstr("Key Left : ");
	my_putstr(param->config->k_left.display);
	my_putstr("\nKey Right : ");
	my_putstr(param->config->k_right.display);
	my_putstr("\nKey Turn : ");
	my_putstr(param->config->k_turn.display);
	my_putstr("\nKey Drop : ");
	my_putstr(param->config->k_drop.display);
	my_putstr("\nKey Quit : ");
	my_putstr(param->config->k_quit.display);
	my_putstr("\nKey Pause : ");
	my_putstr(param->config->k_pause.display);
	my_putstr("\nNext : ");
	if (param->config->next)
		my_putstr("Yes");
	else
		my_putstr("No");
}

void valid_info_display(tetriminos_t *tmp)
{
	my_putstr("Size ");
	my_put_nbr(tmp->width);
	my_putstr("*");
	my_put_nbr(tmp->height);
	my_putstr(" : Color ");
	my_put_nbr(tmp->color);
	my_putstr(" :\n");
	for (int i = 0; tmp->form[i] != NULL; i++) {
		my_putstr(tmp->form[i]);
		my_putstr("\n");
	}
}

void tetriminos_display(main_t *param)
{
	tetriminos_t *tmp = param->tetri;

	while (tmp->next != NULL) {
		if (tmp->next->id >= 0) {
			my_putstr("Tetriminos : Name ");
			my_putstr(tmp->next->name);
			my_putstr(" : ");
			if (tmp->next->invalid == 0)
				valid_info_display(tmp->next);
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
		key_display(param);
		my_putstr("\nLevel : ");
		my_put_nbr(param->config->level);
		my_putstr("\nSize : ");
		my_put_nbr(param->config->size_h);
		my_putstr("*");
		my_put_nbr(param->config->size_w);
		my_putstr("\nTetriminos : ");
		my_put_nbr(param->config->nb_tetri);
		my_putchar('\n');
		tetriminos_display(param);
		my_putstr("Press any key to start Tetris\n");
		line = get_next_line(0);
		free(line);
	}
}
