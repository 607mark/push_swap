NAME = push_swap

SRCS = validity_utils.c \
        utils.c \
        algo.c \
        sort_utils.c \
        easy_sort.c \
        main.c \
        complex_sort.c \
        complex_sort_2.c \
        strategies.c \
        operations/swap.c \
        operations/push.c \
        operations/rotate.c \
        operations/rev_rotate.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = -L./libft -lft

# Default target
all: $(NAME)

# Build the executable
$(NAME): $(OBJS) libft/libft.a
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile libft
libft/libft.a:
	@$(MAKE) -C ./libft
	@touch libft/libft.a

# Remove object files
clean:
	rm -f $(OBJS)
	@$(MAKE) -C ./libft clean

# Remove object files and executable
fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C ./libft fclean

# Rebuild the project
re: fclean all

.PHONY: all clean fclean re

