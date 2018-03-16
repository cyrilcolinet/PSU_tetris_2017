/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** key_manager functions
*/

# include "tetris.h"

char *configure_key_display(char c)
{
	return ("fraise");
}

keym_t config_key(char c)
{
	keym_t keymap;

	keymap.c = c;
	keymap.display = configure_key_display(c);

	return (keymap);
}
