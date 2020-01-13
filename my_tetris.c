/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** falling square game
*/

#include "my_tetris.h"
#include "include/my.h"
#include "include/my_printf.h"
#include "unistd.h"

void display_help_under(void)
{
	my_putstr(" -d --key-drop={K}");
	my_putstr("    DROP the tetrimino using the K key (def: down arrow)\n");
	my_putstr(" -q --key-quit={K}");
	my_putstr("    QUIT the game using the K key (def: 'q' key)\n");
	my_putstr(" -p --key-pause={K}");
	my_putstr("   PAUSE/RESTART the game\
 using the K key (def: space bar)\n");
	my_putstr(" --map-size={row,col}");
	my_putstr(" Set the numbers of rows and\
 columns of the map (def: 20,10)\n");
	my_putstr(" -w --without-next");
	my_putstr("    Hide next tetrimino (def: false)\n");
	my_putstr(" -D --debug           Debug mode (def: false)\n");
}

void display_help(int ac, char **av)
{
	my_putstr("Usage:  ");
	my_printf("%s", av[0]);
	my_putstr(" [options]\n");
	my_putstr("Options:\n");
	my_putstr(" --help");
	my_putstr("               Display this help\n");
	my_putstr(" -L --level={num}     Start Tetris at level num (def: 1)");
	my_putstr("\n -l --key-left={K}");
	my_putstr("    Move the tetrimino LEFT using the K key\
 (def: left arrow)\n");
	my_putstr(" -r --key-right={K}");
	my_putstr("   Move the tetrimino RIGHT\
 using the K key (def: right arrow)\n");
	my_putstr(" -t --key-turn={K}");
	my_putstr("    Turn the tetrimino clockwise 90d using\
 the K key (def: top arrow)\n");
	display_help_under();
}

int tetris(int ac, char **av)
{
	tetris_var_t tetris_var;
	tetris_var_sub_t tetris_access = tetris_var.tetris_var_sub;

	tetris_var.check = 0;
	tetris_var.count_nb = -2;
	if (my_strcmp(av[1], "--help") == 0) {
		display_help(ac, av);
	} else {
		print_elem(ac, av, tetris_var);
	}
	return (0);
}

int main(int ac, char **av)
{
	if (ac < 2) {
		write(2, "Error: you must \
enter at least one argument.\n", 45);
		return (84);
	}
	tetris(ac, av);
	return (0);
}
