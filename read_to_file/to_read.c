/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** read
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../my_tetris.h"
#include "../include/my_sokoban_v2.h"

int read_content_file_sub_loop(tetris_var_sub_t *tetris_access, int i)
{
	int j = 0;
	
	i = i + 3;
	while (tetris_access->tab_content[i] != '\0') {
		if ((tetris_access->tab_content[i] == '*' ||
		     tetris_access->tab_content[i] == ' ' ||
		     tetris_access->tab_content[i] == '\n'))
			tetris_access->tab_content_tetrimino[j] =
				tetris_access->tab_content[i];
		else
			tetris_access->wrong = tetris_access->wrong + 1;
		i++;
		j++;
	}
	return (i);
}

int read_content_file_sub(tetris_var_sub_t *tetris_access, int i)
{
	if ((tetris_access->tab_content[i] <= '9' &&
	     tetris_access->tab_content[i] >= '0') ||
	    tetris_access->tab_content[i] == 32) {
		tetris_access->tab_content_color[0] =
			tetris_access->tab_content[i + 1];
		tetris_access->tab_content_size[1] = '*';
		tetris_access->tab_content_size[i] = '\0';
	} else
		tetris_access->wrong = tetris_access->wrong + 1;
	i = read_content_file_sub_loop(tetris_access, i);
}

int read_content_file_loop(tetris_var_sub_t *tetris_access,
			   tetris_var_t *tetris_var, int i)
{
	while (tetris_access->tab_content[i + 2] != '\n') {
		if ((tetris_access->tab_content[i] <= '9' &&
		     tetris_access->tab_content[i] >= '0') ||
		    tetris_access->tab_content[i] == 32)
			tetris_access->tab_content_size[i] =
				tetris_access->tab_content[i];
		else
			tetris_access->wrong = tetris_access->wrong + 1;
		i++;
	}
	return (i);
}

int read_content_file(tetris_var_sub_t *tetris_access,
		      tetris_var_t *tetris_var)
{
	int i = 0;
	char *file = malloc(sizeof(char *) *
			    my_strlen(tetris_var->tab_name) * 100);
	tetris_access->wrong = 0;

	my_strcpy(file, "./tetriminos/");
	my_strcat(file, tetris_var->tab_name);
	tetris_access->tab_content
		= read_to(file);
	tetris_access->tab_content_size = malloc(sizeof(char *) * 3);
	tetris_access->tab_content_color = malloc(sizeof(char *) * 1);
	tetris_access->tab_content_tetrimino = malloc(sizeof(char *) * 100);
        i = read_content_file_loop(tetris_access, tetris_var, i);
	read_content_file_sub(tetris_access, i);
	print_tetriminos_content(tetris_access);
	return (0);
}
