/*
** EPITECH PROJECT, 2018
** display_map
** File description:
** tetris
*/

#include "tetris.h"

static void create_current(main_t *param, tetriminos_t *tmp)
{
	int nb = 0;

	for (int i = 0; tmp->form[i] != NULL; i++)
		nb++;
	param->current = malloc(sizeof(char *) * (nb + 1));
	param->current[nb] = NULL;
	for (int i = 0; tmp->form[i] != NULL; i++) {
		nb = 0;
		for (int j = 0; tmp->form[i][j] != '\0'; j++)
			nb++;
		param->current[i] = malloc(sizeof(char) * (nb + 1));
		for (int j = 0; tmp->form[i][j] != '\0'; j++)
			param->current[i][j] = tmp->form[i][j];
		param->current[i][nb] = '\0';
	}
}

void display_game(main_t *param)
{
	int n = 1;
	tetriminos_t *tmp = param->tetri;

	param->pos_x = 35;
	param->pos_y = 2;
	
	tmp = tmp->next;
	tmp = tmp->next;

	initscr();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(FALSE);
	use_default_colors();
	start_color();
	init_pair(1, COLOR_RED, -1);
	init_pair(2, COLOR_GREEN, -1);
	init_pair(3, COLOR_YELLOW, -1);
	init_pair(4, COLOR_BLUE, -1);
	init_pair(5, COLOR_MAGENTA, -1);
	init_pair(6, COLOR_CYAN, -1);

	create_current(param, tmp->next);

	while (n != param->config.kq) {
		clear();
		display_form(param->current, param->pos_x, param->pos_y);
		create_tetris_title();
		display_map(param);
		display_score(param);
		display_next_tetri(param, tmp->next);
		n = getch();
		deplacement(param, n);
		refresh();
	}
	endwin();
}
