/*
** EPITECH PROJECT, 2018
** lib
** File description:
** lib
*/

#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

char *my_get_line(const int fd)
{
	char save[SIZE];
	unsigned long i = 0;
	unsigned long g = 0;
	unsigned long f = 0;
	char *save_2 = NULL;

	g = read(fd, save, SIZE + 1);
	save[g] = '\0';
	save_2 = malloc((sizeof(*save_2) * SIZE));
	while (save[i] != '\n' && save[i] != '\0')
		save_2[f++] = save[i++];
	save_2[f] = '\0';
	return (save_2);
}
