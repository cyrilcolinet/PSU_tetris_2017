/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** fill_struct functions
*/

# include "tetris.h"

void set_start_values(char *line, tetriminos_t *tetri)
{
	char **arr = NULL;

	arr = my_strtok(line, ' ');
	tetri->width = my_atoi(arr[0]);
	tetri->height = my_atoi(arr[1]);
	tetri->color = my_atoi(arr[2]);
	my_freetab(arr);
}

void move_form(char **form, tetriminos_t *tetri)
{
	int count = 0;
	int i = 0;

	for (count = 0; form[count]; count++);
	while (form[i++] != NULL) {
		tetri->form[i] = form[i - 1];
	}

	tetri->form[count] = NULL;
}

char **get_form(char *path, tetriminos_t *tetri)
{
	char **arr = malloc(sizeof(char *) * (tetri->height + 1));
	int i = 0;
	int fd = open(path, O_RDONLY);

	if (arr == NULL || fd < 0)
		return (NULL);

	for (i = 0; arr[i] != NULL; i++) {
		arr[i] = get_next_line(fd);
	}

	arr[tetri->height] = NULL;
	close(fd);
	return (arr);
}

void fill_tetriminos(main_t *param, files_t *file)
{
	tetriminos_t *tmp = NULL;

	if (param->tetri == NULL || file == NULL)
		return;

	tmp = param->tetri;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = malloc(sizeof(tetriminos_t));
	if (tmp->next == NULL)
		return;
	tmp->next->id = file->id;
	tmp->next->name = file->name;
	tmp->next->path = file->path;
	tmp->next->form = get_form(file->path, tmp->next);
	set_start_values(tmp->next->form[0], tmp->next);
	move_form(tmp->next->form, tmp->next);
	tmp->next->next = NULL;
	printf("w, h, c: %d %d %d\n", tmp->next->width, tmp->next->height, tmp->next->color);
	printf("name: %s\n", tmp->next->name);
	for (int i = 0; tmp->next->form[i]; i++)
		printf("form[%d]: %s\n", i, tmp->next->form[i]);
	printf("\n");
}
