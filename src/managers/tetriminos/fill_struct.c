/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** fill_struct functions
*/

# include "tetris.h"

char **get_form(char *path, tetriminos_t *tetri)
{
	char **arr;
	char *tmp;
	char **test;
	int i = 0;
	int fd = open(path, O_RDONLY);

	if (fd < 0)
		return (NULL);

	tmp = get_next_line(fd);
	printf("TMP =  %s\n", tmp);
	for (int i = 0; tmp[i] != '\0'; i++)
		if ((tmp[i] < '0' || tmp[i] > '9') && tmp[i] != ' ') {
			free(tmp);
			return(NULL);
		}
	test = my_strtok(tmp, ' ');
	tetri->width = my_atoi(test[0]);
	tetri->height = my_atoi(test[1]);
	tetri->color = my_atoi(test[2]);
	arr = malloc(sizeof(char *) * (tetri->height + 1));
	for (int i = 0; i < tetri->height; i++) {
		arr[i] = get_next_line(fd);
	}
	arr[tetri->height] = NULL;
	close(fd);
	free(tmp);
	for (int i = 0; test[i] != NULL; i++)
		free(test[i]);
	free(test);
	return (arr);
}

void fill_tetriminos(main_t *param, files_t *file)
{
	tetriminos_t *tmp = NULL;

	if (param->tetri == NULL || file == NULL)
		return;

	tmp = param->tetri;
	while (tmp != NULL)
		tmp = tmp->next;

	tmp = malloc(sizeof(tetriminos_t));
	if (tmp == NULL)
		return;
	tmp->id = file->id;
	tmp->name = file->name;
	tmp->path = file->path;
	tmp->form = get_form(file->path, tmp);
	tmp->next = NULL;

	/* if (tmp->form == NULL) { */
	/* 	printf("name: %s\n", tmp->name); */
	/* } else { */
		
	/* 	tmp->next = NULL; */
	/* 	printf("w, h, c: %d %d %d\n", tmp->width, tmp->height, tmp->color); */
	/* 	printf("name: %s\n", tmp->name); */
	/* 	for (int i = 0; tmp->form[i]; i++) */
	/* 		printf("form[%d]: %s\n", i, tmp->form[i]); */
	/* } */
	/* printf("\n");	 */
}
