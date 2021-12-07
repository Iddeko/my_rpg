##
## EPITECH PROJECT, 2021
## my_rpg
## File description:
## makefile
##

SRC =	clear_utils.c \
		create_utils.c \
		event_handler.c \
		setup_utils.c \
		write_usage.c \

MAIN =	main.c \

OBJ = $(SRC:.c=.o)
MAINOBJ = $(MAIN:.c=.o)

NAME = my_rpg
CFLAGS = -I include/
LIB = lib/libmy.a
CFLAGS += -Wall -Wextra -g3
LDFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lm

all: $(NAME)

$(NAME): $(OBJ) $(MAINOBJ)
	make re -C lib/my/
	gcc -o $(NAME) $(OBJ) $(MAINOBJ) $(LIB) $(CFLAGS) $(LDFLAGS)

re: fclean all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
