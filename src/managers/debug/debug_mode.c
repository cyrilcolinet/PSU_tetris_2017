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
	my_putstr("Key Left :  ");
	my_putstr("");
	my_putstr("\nKey Right :  ");
	my_putstr("");
	my_putstr("\nKey Turn :  ");
	my_putstr("");
	my_putstr("\nKey Drop :  ");
	my_putstr("");
	my_putstr("\nKey Quit :  ");
	my_putstr("");
	my_putstr("\nKey Pause :  ");
	my_putstr("");
	my_putstr("\nNext :  ");
	my_putstr("Yes");
	my_putstr("No");
	my_putstr("\nLevel :  ");
	my_put_nbr(1);
	my_putstr("\nSize :  ");
	my_put_nbr(1);
	my_putstr("*");
	my_put_nbr(1);
	my_putstr("\nTetriminos :  ");
	my_put_nbr(1);
	my_putchar('\n');
	param->debug = 1;
}
