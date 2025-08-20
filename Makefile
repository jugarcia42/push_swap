NAME = push_swap

SRC = main.c ksort.c ksort_utils.c parse_stack.c parse.c \
      push_operations.c reverse_operations.c rotate_operations.c \
      sortest.c swap_operations.c

OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I$(LIBFT_DIR) -I.

CC = cc
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
