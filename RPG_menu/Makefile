##
## EPITECH PROJECT, 2021
## runner - Makefie
## File description:
## makes the file
##

SRC		=	menu.c \

OBJ		=	$(SRC:.c=.o)

FLAGS	=	-Wall \
			-Wextra \
			-o \

NAME	=	menu

LIB		=	-lcsfml-graphics \
			-lcsfml-system \
			-lcsfml-audio \
			-lcsfml-window \

all		:	$(OBJ)
			gcc $(FLAGS) $(NAME) $(OBJ) $(LIB)

clean	:
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)

re		:	clean all

plus	:	all clean
			clear;

obj		: $(OBJ)