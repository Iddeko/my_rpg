##
## EPITECH PROJECT, 2021
## My_RPG
## File description:
## MAKEFILE
##

## ===========================================================
## ===========================[VAR]===========================
## ===========================================================

NAME			=			my_rpg

NAME_TEST		=			unit_test

## ==========================[PATHS]==========================

SRC_PATH		=			src/

## ===========================[SRC]===========================

SRC				=			$(SRC_PATH)menu.c				\
							$(SRC_PATH)get_keyboard_input.c	\
							$(SRC_PATH)pause_menu.c			\
							$(SRC_PATH)mouse.c				\
							$(SRC_PATH)csfml_utils.c		\

main			=											\

OBJ				=			$(SRC:.c=.o)

CRIT			=			-lcriterion --coverage

## =========================[OPTIONS]=========================

FLAGS		=	-Wall \
				-Wextra \

CPPFLAGS	=	-I include/

LDFLAGS		=	-L lib -lmy

LIB			=	lib/libmy.a \
				-lcsfml-graphics \
				-lcsfml-system \
				-lcsfml-audio \
				-lcsfml-window \

## ===========================================================
## ==========================[RULES]==========================
## ===========================================================

all			:	$(OBJ)
				make re -C lib/my/
				$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIB) $(CPPFLAGS) $(LDFLAGS)

clean		:
				$(RM) -f $(OBJ)

fclean		:	clean
				$(RM) -f $(NAME)

re			:	clean all

plus		:	all clean
				clear;

obj			:	$(OBJ)

## ===========================[END]===========================

.PHONY:	all	re	clean	fclean	tests_run
