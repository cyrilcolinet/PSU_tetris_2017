/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** key_manager functions
*/

# include "tetris.h"

char *configure_key_display(char c)
{
	char *str = my_strconfigure(1);
	if (c == 68)
		return (my_strdup("^EOD"));
	if (c == 67)
		return (my_strdup("^EOC"));
	if (c == 65)
		return (my_strdup("^EOA"));
	if (c == 66)
		return (my_strdup("^EOB"));
	if (c == 32)
		return (my_strdup("(space)"));

	str[0] = c;
	return (str);
}

keym_t config_key(char c)
{
	keym_t keymap;

	keymap.c = c;
	keymap.display = configure_key_display(c);

	return (keymap);
}
