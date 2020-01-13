##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compile the libmy
##

CC = gcc

RM = rm -f

SRC =	read_to_file/to_read.c \
	read_to_file/to_read_next.c \
	read_to_file/to_print.c \
	read_to_file/to_print_condition.c \
	read_to_param/to_param.c \
	my_tetris.c

OBJ = $(SRC:.c=.o)

NAME = tetris

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	$(MAKE) -C libmy
	$(CC) $(OBJ) -o $(NAME) -L libmy -l my
clean:
	$(RM) $(OBJ)

fclean: clean
	make -C libmy fclean
	$(RM) $(NAME)

re: fclean all

.PHONY : all fclean clean re
