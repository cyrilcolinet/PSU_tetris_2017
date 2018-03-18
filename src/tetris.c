/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** tetris functions
*/

# include "tetris.h"

int check_nb_valid(main_t *param)
{
	tetriminos_t *tmp = param->tetri;
	int nb = 0;

	while (tmp->next != NULL) {
		if (tmp->next->invalid == 0)
			nb++;
		tmp = tmp->next;
	}
	return (nb);
}

int tetris(main_t *param)
{
	if (config_tetriminos(param) != 0)
		return (84);
	keypad(stdscr, TRUE);
	arguments_manager(param);
	error_form(param);
	debug_mode(param);
	if (param->config->nb_tetri <= 0 || (check_nb_valid(param)) <= 0) {
		my_putstr("no valid tetrimino detected\n");
		return (84);
	}
	display_game(param);
	return (0);
}

int tetris_main(int ac, char **av)
{
	main_t *param;
	int err;

	param = configure();
	if (param == NULL)
		return (84);
	param->ac = ac;
	param->av = av;
	err = tetris(param);
	free_all(param);
	return (err);
}

void display_help(main_t *param)
{
	my_putstr("Usage: ");
	my_putstr(param->av[0]);
	my_putstr(" [options]\n");
	my_putstr("Options:\n");
	my_putstr(" --help\t\t\tDisplay this help\n");
	my_putstr(" -L --level={num}\tStart Tetris at level num (def: 1)\n -l");
	my_putstr(" --key-left={K}\tMove the tetrimino LEFT using the K key ");
	my_putstr("(def: left arrow)\n -r --key-right={K}\tMove the tetrimino");
	my_putstr(" right using the K key (def: right arrow)\n -t --key-turn=");
	my_putstr("{K}\tTURN the tetrimino clockwise 90d using the K key (def");
	my_putstr(": top arrow)\n -d --key-drop={K}\tDROP the tetrimino using");
	my_putstr(" the K key (def: down arrow)\n -q --key-quit={K}\tQUIT the");
	my_putstr(" game using the K key (def: 'q' key)\n -p --key-pause={K}");
	my_putstr("\tPAUSE/RESTART the game using the K key (def: space bar)");
	my_putstr("\n --map-size={row,col}\tSet the numbers of rows and colum");
	my_putstr("ns of the map (def: 20,10)\n -w --without-next\tHide next ");
	my_putstr("tetrimino (def: false)\n -D --debug\t\tDebug mode (def: ");
	my_putstr("false)\n");
	free_all(param);
	exit(0);
}
