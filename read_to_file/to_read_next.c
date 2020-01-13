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

int read_tetris_cond(tetris_var_t *tetris_var)
{
	if (tetris_var->folder->d_name != "."
	    && tetris_var->folder->d_name != ".."
	    && tetris_var->folder->d_name != ".git") {
		tetris_var->tab_name =
			malloc(sizeof(char *) *
			       my_strlen(tetris_var->folder->d_name) + 1);
		tetris_var->tab_name =
			tetris_var->folder->d_name;
	}
	return (my_strlen(tetris_var->tab_name));
}

int read_tetris_loop(tetris_var_t *tetris_var, tetris_var_sub_t *tetris_access)
{
	int i = 0;

	while ((tetris_var->tab_name[i]) != '.') {
		tetris_access->tab_name_op[i] =
			tetris_var->tab_name[i];
		i++;
	}
}

int read_tetris(int ac, char **av, tetris_var_t *tetris_var,
		tetris_var_sub_t *tetris_access)
{
	int i;
	int size;

	tetris_var->dir = opendir("./tetriminos");
	while ((tetris_var->folder = readdir(tetris_var->dir)) != NULL) {
		if (tetris_var->folder->d_type == DT_REG) {
			size = read_tetris_cond(tetris_var);
			tetris_access->tab_name_op = malloc(sizeof(char *)
							    * size);
			read_tetris_loop(tetris_var, tetris_access);
			read_content_file(tetris_access, tetris_var);
		}
		tetris_var->count_nb++;
	}
	closedir(tetris_var->dir);
}
