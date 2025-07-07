##
## EPITECH PROJECT, 2025
## makefile
## File description:
## makefile
##

SRC = my_show_word_array.c\
	my_putchar.c\
	my_strcat.c\
	my_strlen.c\
	my_strncpy.c\
	my_put_nbr.c\
	my_strcmp.c\
	my_getnbr.c\
	my_putstr.c\
	my_strcpy.c\
	my_strdup.c\
	my_strncat.c\
	my_heapcat.c\
	my_str_to_word_array.c\
	my_strncmp.c\
	throw_error.c\
	free_word_array.c\
	printf/my_printf.c	\
	printf/specific_flags/my_put_base.c	\
	printf/specific_flags/flag_u.c	\
	printf/specific_flags/print_prct.c	\
	printf/specific_flags/flag_p.c	\
	printf/between/flags_csid.c	\
	printf/between/flags_hex.c	\
	printf/between/flag_p.c	\

NAME =	libmy.a

OBJ =	$(SRC:.c=.o)

CFLAGS = -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../

clean:
	$(RM) $(OBJ)

fclean:     clean
	$(RM) $(NAME)
	$(RM) ../libmy.a
	$(RM) ../../libmy.a

re:     fclean all
