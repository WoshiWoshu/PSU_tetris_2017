/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** print condition
*/

#include <stddef.h>
#include "../include/my.h"
#include "../my_tetris.h"
#include "../include/my_printf.h"

int print_elem_cond_sub_sub(param_value_t *param_value)
{
	if (param_value->opt_p == NULL)
		my_putstr("Key Pause :  (pause)\n");
	if (param_value->opt_p != NULL) {
		my_putstr("Key Pause :  ");
		my_printf("%s\n", param_value->opt_p);
	}
	if (param_value->opt_w == NULL)
		my_putstr("Next :  Yes\n");
	if (param_value->opt_w != NULL) {
		my_putstr("Next :  ");
		my_printf("%s\n", param_value->opt_w);
	}
	if (param_value->opt_l_maj == NULL)
		my_putstr("Level :  1\n");
	if (param_value->opt_l_maj != NULL) {
		my_putstr("Level :  ");
		my_printf("%s\n", param_value->opt_l_maj);
	}
}

int print_elem_cond_sub(param_value_t *param_value)
{
	if (param_value->opt_t == NULL)
		my_putstr("Key Turn :  ^EOA\n");
	if (param_value->opt_t != NULL) {
		my_putstr("Key Turn :  ");
		my_printf("%s\n", param_value->opt_t);
	}
	if (param_value->opt_d == NULL)
		my_putstr("Key Drop :  ^EOB\n");
	if (param_value->opt_d != NULL) {
		my_putstr("Key Drop :  ");
		my_printf("%s\n", param_value->opt_d);
	}
	if (param_value->opt_q == NULL)
		my_putstr("Key Quit :  q\n");
	if (param_value->opt_q != NULL) {
		my_putstr("Key Quit :  ");
		my_printf("%s\n", param_value->opt_q);
	}
	print_elem_cond_sub_sub(param_value);
}

int print_elem_cond(param_value_t *param_value)
{
	if (param_value->opt_l == NULL)
		my_putstr("Key Left :  ^EOD\n");
	if (param_value->opt_l != NULL) {
		my_putstr("Key Left :  ");
		my_printf("%s\n", param_value->opt_l);
	}
	if (param_value->opt_r == NULL)
		my_putstr("Key Right :  ^EOC\n");
	if (param_value->opt_r != NULL) {
		my_putstr("Key Right :  ");
		my_printf("%s\n", param_value->opt_r);
	}
	print_elem_cond_sub(param_value);
	if (param_value->opt_m == NULL)
		my_putstr("Size :  20*10\n");
	if (param_value->opt_m != NULL) {
		my_putstr("Size :  ");
		my_printf("%s\n", param_value->opt_m);
	}
}
