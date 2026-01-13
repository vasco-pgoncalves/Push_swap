# ==============================
# Variables
# ==============================

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes -I libft -I ft_printf

# Push_swap source files (all parsing files)
SRC = src/parsing/parse.c \
      src/parsing/max_range.c \
      src/parsing/separate.c \
      src/parsing/duplicates.c \
      src/parsing/validade.c \
      src/parsing/utils.c

# Libft source files (all of them)
LIBFT_SRC = $(wildcard libft/*.c)

# ft_printf source files (all of them)
PRINTF_SRC = $(wildcard ft_printf/*.c)

# Object files
OBJ = $(SRC:.c=.o) $(LIBFT_SRC:.c=.o) $(PRINTF_SRC:.c=.o)

# ==============================
# Rules
# ==============================

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Generic rule to compile .c to .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
