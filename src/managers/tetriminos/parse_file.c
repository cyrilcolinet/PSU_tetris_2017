/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** parse_file functions
*/

# include "tetris.h"

char *get_first_line(char *file)
{
	int fd = open(file, O_RDONLY);
	char *ret = NULL;
	char *chr = NULL;
	char buff[20];

	if (fd < 0)
		return (NULL);

	if (read(fd, buff, 19) < 0)
		return (NULL);

	chr = my_strchr(buff, '\n');
	if (error_size_color(chr) == 1) {
		free(chr);
		close(fd);
		return (NULL);
	}
	ret = my_strdup(chr);
	free(chr);
	close(fd);
	return (ret);
}

int set_first_values(tetriminos_t *tmp, char *path)
{
	char *line = get_first_line(path);
	char **tab = NULL;

	if (line == NULL)
		return (1);

	tab = my_strtok(line, ' ');
	free(line);

	if (tab[2] == NULL) {
		my_freetab(tab);
		return (1);
	}

	tmp->width = my_atoi(tab[0]);
	tmp->height = my_atoi(tab[1]);
	tmp->color = my_atoi(tab[2]);
	my_freetab(tab);
	return (0);
}

char *parse_filename(char *file)
{
	char **arr = NULL;
	char *ret = NULL;

	if (file == NULL)
		return (NULL);

	arr = my_strtok(file, '.');
	ret = my_strdup(arr[0]);
	my_freetab(arr);

	return (ret);
}

char **get_tetrimino_form(char *file, int height)
{
	char **tab = malloc(sizeof(char *) * (height + 1));
	int fd = -1;
	int loop = -1;
	char *line = NULL;

	if (tab == NULL)
		return (NULL);
	if ((fd = open(file, O_RDONLY)) < 0)
		return (NULL);
	while ((line = get_next_line(fd))) {
		if (loop >= 0)
			tab[loop] = my_strdup(line);
		free(line);
		loop++;
	}
	free(line);
	tab[height] = NULL;
	close(fd);
	return (tab);
}
