/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** my_strchr
*/

# include "my.h"

static int get_wlen(char *str, char delim)
{
	int i = 0;
	int len = 0;

	while (str[i] == delim)
		i++;
	while (str[i] != delim && str[i]) {
		i++;
		len++;
	}
	return (len);
}

char *my_strchr(char *str, char delimiter)
{
	char *ret = NULL;
	int wlen = 0;
	int i = 0;
	int j = 0;
	int k = 0;

	if (str == NULL)
		return (NULL);

	wlen = get_wlen(str, '\n');
	ret = my_strconfigure(wlen + 1);
	if (ret == NULL)
		return (NULL);

	for (i = 0; str[i] == delimiter; i++);
	while (str[i] != delimiter && str[i])
		ret[k++] = str[i++];
	ret[k] = 0;
	return (ret);
}
