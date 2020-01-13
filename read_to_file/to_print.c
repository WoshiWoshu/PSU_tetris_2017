/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** print
*/

#include <sys/types.h>
#include <dirent.h>
#include <stddef.h>
#include "../include/my.h"
#include "../my_tetris.h"
#include "../include/my_printf.h"

void init_struct_opt(int ac, char **av, param_value_t *param_value)
{
	param_value->opt_l = NULL;
	param_value->opt_r = NULL;
	param_value->opt_t = NULL;
	param_value->opt_l_maj = NULL;
	param_value->opt_d = NULL;
	param_value->opt_q = NULL;
	param_value->opt_p = NULL;
	param_value->opt_w = NULL;
	param_value->opt_d_maj = NULL;
	param_value->opt_m = NULL;
	parse_opt_param_long(ac, av, param_value);
	parse_opt_param(ac, av, param_value);
}

int print_elem(int ac, char **av, tetris_var_t tetris_var)
{
	param_value_t param_value = tetris_var.tetris_var_sub.param_value;
	tetris_var_sub_t tetris_access = tetris_var.tetris_var_sub;

	init_struct_opt(ac, av, &param_value);
	if (tetris_var.check == 0) {
		if (param_value.opt_d_maj != NULL) {
			my_putstr("*** DEBUG MODE ***\n");
			print_elem_cond(&param_value);
			print_tetriminos_nb(&tetris_var);
			read_tetris(ac, av, &tetris_var, &tetris_access);
			my_putstr("Press any key to start Tetris\n");
		}
		if (param_value.opt_d_maj == NULL) {
			return (1);
		}
	}
	return (0);
}

int print_tetriminos_nb(tetris_var_t *tetris_var)
{
	tetris_var->dir = opendir("./tetriminos");
	while ((tetris_var->folder = readdir(tetris_var->dir)) != NULL) {
		tetris_var->count_nb++;
	}
	closedir(tetris_var->dir);
	my_putstr("Tetriminos :  ");
	my_printf("%d\n", tetris_var->count_nb);
	tetris_var->check = tetris_var->check + 1;
	return (0);
}

int print_tetriminos_content(tetris_var_sub_t *tetris_access)
{
	my_putstr("Tetriminos :  Name ");
	my_printf("%s :  ", tetris_access->tab_name_op);
	if (tetris_access->wrong == 0) {
		my_putstr("Size ");
		my_printf("%s :  ", tetris_access->tab_content_size);
		my_putstr("Color ");
		my_printf("%s :\n", tetris_access->tab_content_color);
		my_printf("%s", tetris_access->tab_content_tetrimino);
	} else {
		my_putstr("Error\n");
	}
}
