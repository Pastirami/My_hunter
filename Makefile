##
## EPITECH PROJECT, 2025
## makefile
## File description:
## makefile makefile
##

SRC 	=	main.c						\
			src/core.c					\
			src/destroy.c				\
			src/destroy2.c				\
			src/init.c					\
			src/main_loop.c				\
			src/update_sprite.c			\
			src/handle_events.c			\
			src/update_explosion.c		\
			src/handle_args.c			\


OBJ		=	$(SRC:.c=.o)

CPPFLAGS +=	-iquote ./include

CFLAGS +=	-Wall -Wextra -pedantic -g3

LDFLAGS =	-L./lib -lmy

CC	= gcc

CSFML	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window -lm

NAME =	my_hunter

CRT	=	--coverage -lcriterion

all:	$(NAME)

$(NAME): $(OBJ)
	make -C lib/my/
	$(CC) -g $(OBJ) -o $(NAME) $(CPPFLAGS) $(LDFLAGS) $(CFLAGS) $(CSFML)

clean:
	make clean -C lib/my/
	rm -f $(OBJ)

fclean: clean
	make fclean -C lib/my/
	rm -f $(NAME)

debug: fclean $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) $(DEBUGFALG) $(CSFML)

re: fclean all clean

.PHONY: all re clean fclean
