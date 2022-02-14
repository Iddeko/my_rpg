##
## EPITECH PROJECT, 2021
## BSQ
## File description:
## make file lib
##

SRC	=	my_swap.c \
		my_arrlen.c \
		my_strcat.c \
		my_printf.c \
		my_strcmp.c \
		my_strlen.c \
		my_strstr.c \
		my_getnbr.c \
		my_strcpy.c \
		my_strdup.c \
		my_substr.c \
		my_revstr.c \
		my_strncpy.c \
		my_put_int.c \
		my_put_nbr.c \
		my_strncat.c \
		my_strncmp.c \
		my_is_prime.c \
		my_strsplit.c \
		my_str_isnum.c \
		my_strupcase.c \
		my_char_isnum.c \
		my_strlowcase.c \
		my_printf_hex.c \
		my_printf_hex2.c \
		my_getoperator.c \
		my_str_isalpha.c \
		my_dec_to_base.c \
		my_printf_octal.c \
		my_char_isalpha.c \
		my_printf_utils.c \
		my_strcapitalize.c \
		my_printf_binary.c \
		my_printf_types3.c \
		my_put_long_long.c \
		my_compute_power.c \
		my_str_isoperator.c \
		my_printf_types_s.c \
		my_printf_unsigned.c \
		my_printf_pointeur.c \
		my_char_isoperator.c \
		my_delete_all_char.c \
		my_rename_all_char.c \
		my_dec_to_base_long.c \
		my_printf_types_int.c \
		my_printf_modifiers.c \
		my_printf_types_s_f.c \
		my_compute_square_root.c \
		my_dec_to_base_unsigned.c \

OBJ =	$(SRC:.c=.o)
CPPFLAGS =	-I ./
NAME =	libmy.a
CC = gcc
MY =	my.h

TEST = 	unit_tests
TESTS = tests/test_lib.c

CFLAGS = -Werror -Wextra

all: $(OBJ)
	ar rc -o $(NAME) $(OBJ)
	cp $(NAME) ../$(NAME)
	mkdir -p ../../include
	cp $(MY) ../../include/$(MY)

clean:
	rm -f $(OBJ)
	rm -f *.gcda
	rm -f *.gcno

fclean: clean
	rm -f $(NAME)

re:     fclean all

tests_run:
	rm -f *.gcda
	rm -f *.gcno
	gcc -o $(TEST) $(SRC) $(TESTS) -I. --coverage -lcriterion -Wall -Wextra
	./$(TEST)
