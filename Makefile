CC = cc 
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
HEADER = ft_printf.h
SOURCE = ft_printf.c ft_print_hex.c ft_print_num.c
OBJ = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)

.PHONY: all clean re run
