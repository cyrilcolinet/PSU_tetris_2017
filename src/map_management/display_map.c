/*
** EPITECH PROJECT, 2018
** display_map
** File description:
** tetris
*/

#include "tetris.h"

void display_map(main_t *main)
{
	initsrc();
	keypad(stdscr, TRUE);
	raw();
	noecho();	
	while (1) {
		clear();
		curs_set(FALSE);
		mvprintw( 0, 0 "kek");
	}
}
