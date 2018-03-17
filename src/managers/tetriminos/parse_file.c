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
	char *ret = NULL;
	int len = my_strlen(file);

	if (file == NULL)
		return (NULL);
	len = len - 10;
	ret = malloc(sizeof(char) * (len + 1));
	for (int i = 0; i < len; i++)
		ret[i] = file[i];
	ret[len] = '\0';
	return (ret);
}

static char *clear_str(char *str)
{
	int nb = 0;
	int len = 0;
	char *s;

	for (int i = 0; str[i] != '\0'; i++) {
		nb = 0;
		while (str[i] != '*' && str[i] != '\0') {
			nb++;
			i++;
		}
		if (str[i] == '*')
			len += (nb + 1);
	}
	s = malloc(sizeof(char) * (len + 1));
	for (int i = 0; i < len; i++)
		s[i] = str[i];
	s[len] = '\0';
	free(str);
	return (s);
}

char **get_tetrimino_form(char *file, int height)
{
	char **tab = malloc(sizeof(char *) * (height + 1));
	int fd = -1;
	char *line = NULL;

	if (tab == NULL)
		return (NULL);
	if ((fd = open(file, O_RDONLY)) < 0)
		return (NULL);
	for (int loop = -1; (line = get_next_line(fd)); loop++) {
		if (loop >= 0) {
			line = clear_str(line);
			tab[loop] = my_strdup(line);
		}
		free(line);
	}
	free(line);
	tab[height] = NULL;
	close(fd);
	return (tab);
}
