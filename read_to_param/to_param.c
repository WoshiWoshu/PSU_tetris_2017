/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** param parse
*/

#include <getopt.h>
#include <stdio.h>
#include "../my_tetris.h"

void parse_opt_param_cond_sub(int option_index, param_value_t *param_value)
{
	switch (option_index) {
	case 'q':
		param_value->opt_q = optarg;
		break;
	case 'p':
		param_value->opt_p = optarg;
		break;
	case 'w':
		param_value->opt_w = optarg;
		break;
	case 'D':
		param_value->opt_d_maj = "1";
		break;
	case 'm':
		param_value->opt_m = optarg;
		break;
	}
}

void parse_opt_param_cond(int option_index, param_value_t *param_value)
{
	switch (option_index) {
	case 'L':
		param_value->opt_l_maj = optarg;
		break;
	case 'l':
		param_value->opt_l = optarg;
		break;
	case 'r':
		param_value->opt_r = optarg;
		break;
	case 't':
		param_value->opt_t = optarg;
		break;
	case 'd':
		param_value->opt_d = optarg;
		break;
	default:
		parse_opt_param_cond_sub(option_index, param_value);
	}
}

int parse_opt_param(int ac, char **av, param_value_t *param_value)
{
	int option_index = 0;
	char *param_opt = "-L:-l:-r:-t:-d:-q:-p:-w:-D";

	while ((option_index = getopt(ac, av, param_opt)) != -1) {
		parse_opt_param_cond(option_index, param_value);
	}
	return (0);
}

int parse_opt_param_long(int ac, char **av, param_value_t *param_value)
{
	int index;
	int opt_long = 0;
	const struct option longopts[] = {
		{"key-pause=", required_argument, 0, 'p'},
		{"key-left=", required_argument, 0, 'l'},
		{"key-turn=", required_argument, 0, 't'},
		{"key-right=", required_argument, 0, 'r'},
		{"key-drop=", required_argument, 0, 'd'},
		{"key-quit=", required_argument, 0, 'q'},
		{"level=", required_argument, 0, 'L'},
		{"map-size=", required_argument, 0, 'm'},
		{"without-next", required_argument, 0, 'w'},
		{"--debug", required_argument, 0, 'D'},
		{0, 0, 0, 0},
	};
	while ((opt_long = getopt_long(ac, av, "p:l:t:r:d:q:L:m:w:D",
				       longopts, NULL)) != -1) {
		parse_opt_param_cond(opt_long, param_value);
	}
	return (0);
}
