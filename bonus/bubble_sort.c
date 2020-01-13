/*
** EPITECH PROJECT, 2018
** push_swap
** File description:
** function that sort in ascending order a list
*/

#include "include/my.h"
#include <stdio.h>
#include <stdlib.h>

void swap_elem(int *element_next, int *element)
{
	int slot;

	slot = *element;
	*element = *element_next;
	*element_next = slot;
}

int bubble_sort_list(int *list)
{
	int swapped = 0;

	for (int i = 0;list[i] != '\0';i++) {
		if (list[i] > list[i + 1]) {
			swap_elem(list[i + 1], &list[i]);
			swapped = 1;
		}
		printf("%d\n", list[i]);
	}
	if (swapped == 0) {
		return (0);
	} else {
		bubble_sort_list(list);
	}
}

int main(int ac, char **av)
{
	int tab[4] = {3, 2, 1, '\0'};
	bubble_sort_list(tab);
}
