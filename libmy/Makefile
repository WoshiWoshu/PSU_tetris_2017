##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compile the libmy
##
AR = ar rc
RM = rm -f
SRCS =	my_revstr.c \
	my_strcpy.c \
	my_putchar.c \
	my_strncpy.c \
	my_put_nbr.c \
	my_putstr.c \
	my_strcat.c \
	my_strlen.c \
	my_strcmp.c \
	my_get_line.c \
	sokoban_lib/read.c \
	my_printf/my_put_nbr_flag_u.c \
	my_printf/my_printf_condition_content_part1_and_part2.c \
	my_printf/decimal_to_octal_man_ascii.c \
	my_printf/decimal_to_binary.c  \
	my_printf/decimal_to_hexadecimal.c \
	my_printf/decimal_to_hexadecimal_for_flag_p.c \
	my_printf/decimal_to_hexadecimal_conditions_for_flag_p.c \
	my_printf/decimal_to_octal_condition.c \
	my_printf/decimal_to_hexadecimal_conditions.c \
	my_printf/decimal_to_octal.c \
	my_printf/my_printf.c \
	my_printf/my_printf_condition_part1.c \
	my_printf/my_printf_condition_part2.c

OBJS = $(SRCS:.c=.o)

NAME = libmy.a



all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
cp1:
	$(COPY1)
cp2:
	$(COPY2)

rm:
	$(RM)$(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
