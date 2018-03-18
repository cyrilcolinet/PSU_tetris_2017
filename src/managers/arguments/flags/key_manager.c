/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** key_manager functions
*/

# include "tetris.h"

char check_multitouch(void)
{
	if (my_strequ(optarg, "rightk"))
		return (67);
	if (my_strequ(optarg, "leftk"))
		return (68);
	if (my_strequ(optarg, "topk"))
		return (65);
	if (my_strequ(optarg, "downk"))
		return (66);
	return (0);
}

char *configure_key_display(char c)
{
	char *str = NULL;

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

	str = my_strconfigure(1);
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

void free_keymaps(main_t *param)
{
	free(param->config->k_left.display);
	free(param->config->k_right.display);
	free(param->config->k_turn.display);
	free(param->config->k_drop.display);
	free(param->config->k_quit.display);
	free(param->config->k_pause.display);
}
