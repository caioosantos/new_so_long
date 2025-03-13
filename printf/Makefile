NAME = libftprintf.a
LIB = ar rcs
CC = cc
FLAGS = -Wall -Werror -Wextra

SRCS =	$(wildcard *.c)


OBJECTS = $(SRCS:.c=.o)

INCLUDES =	ft_printf.h

all: $(NAME)

$(NAME): $(OBJECTS)
	$(LIB) $(NAME) $(OBJECTS)


%.o: %.c INCLUDES
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

