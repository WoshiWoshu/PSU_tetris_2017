/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** tetris
*/

#include <sys/types.h>
#include <dirent.h>

typedef struct param_value_t param_value_t;
struct param_value_t {
	char *opt_l_maj;
	char *opt_l;
	char *opt_r;
	char *opt_t;
	char *opt_d;
	char *opt_q;
	char *opt_p;
	char *opt_w;
	char *opt_d_maj;
	char *opt_m;
};

typedef struct tetris_var_sub_t tetris_var_sub_t;
struct tetris_var_sub_t {
	char *tab_name_op;
	char *tab_content;
	char *tab_content_size;
	char *tab_content_color;
	char *tab_content_tetrimino;
	int wrong;
	param_value_t param_value;
};

typedef struct tetris_var_t tetris_var_t;
struct tetris_var_t {
	int check;
	int count_nb;
	DIR *dir;
	struct dirent *folder;
	char *tab_name;
	tetris_var_sub_t tetris_var_sub;
};

int tetris(int ac, char **av);
int print_tetriminos_nb(tetris_var_t *tetris_var);
int read_tetris(int ac, char **av, tetris_var_t *tetris_var,
		tetris_var_sub_t *tetris_access);
int print_elem(int ac, char **av, tetris_var_t tetris_var);
int read_tetris_cond(tetris_var_t *tetris_var);
int read_tetris_loop(tetris_var_t *tetris_var, tetris_var_sub_t *tetris_access);
int read_content_file(tetris_var_sub_t *tetris_access,
		      tetris_var_t *tetris_var);
int print_tetriminos_content(tetris_var_sub_t *tetris_access);
void parse_opt_param_cond(int option_index, param_value_t *param_value);
int parse_opt_param(int ac, char **av, param_value_t *param_value);
int parse_opt_param_long_cond(int opt_long);
int parse_opt_param_long(int ac, char **av, param_value_t *param_value);
int print_elem_cond(param_value_t *param_value);
int print_elem_cond_sub_sub(param_value_t *param_value);
int print_elem_cond_sub(param_value_t *param_value);
void parse_opt_param_cond_sub(int option_index, param_value_t *param_value);
void init_struct_opt(int ac, char **av, param_value_t *param_value);
void display_help(int ac, char **av);
void display_help_under(void);
int read_content_file_sub(tetris_var_sub_t *tetris_access, int i);
int read_content_file_loop(tetris_var_sub_t *tetris_access,
			   tetris_var_t *tetris_var, int i);
int read_content_file_sub_loop(tetris_var_sub_t *tetris_access, int i);
