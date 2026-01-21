# ==============================
# Variables
# ==============================

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes -I libft -I ft_printf

# ==============================
# Source files
# ==============================

# Parsing files
SRC_PARSING = src/parsing/parse.c \
              src/parsing/max_range.c \
              src/parsing/separate.c \
              src/parsing/duplicates.c \
              src/parsing/validade.c \
              src/parsing/utils.c

# Operations files
SRC_OPERATIONS = src/operations/push.c \
                 src/operations/rotate.c \
                 src/operations/rev_rotate.c \
                 src/operations/swap.c

# Algorithm files
SRC_ALGORITHM = src/algorithm/turk.c \
                src/algorithm/turk_utils.c \
                src/algorithm/sorting_utils.c \
                src/algorithm/b_to_a.c

# Main file
SRC_MAIN = src/push_swap.c

# Combine all source files
SRC = $(SRC_PARSING) $(SRC_OPERATIONS) $(SRC_ALGORITHM) $(SRC_MAIN)

# Libft source files
LIBFT_SRC = $(wildcard libft/*.c)

# ft_printf source files
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
