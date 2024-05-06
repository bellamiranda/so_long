.SILENT:
.ONESHELL:

# Name of the executable
NAME = so_long

# Source files and object files
SRCS = get_next_line.c get_next_line_utils.c \
	utils.c map.c map_validations.c free.c \
	valid_paths.c game.c moves.c moves_2.c \
	bonus.c bonus_moves.c main.c

OBJS = $(SRCS:.c=.o)

# Compiler and flags
CC = cc
CFLAGS = -g -Wall -Wextra -Werror

# Library directories and libraries
MLX_DIR = minilibx-linux/
MLX = $(MLX_DIR)libmlx.a

# Link against required libraries
MLXFLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

# Build the executable
all: $(NAME)

$(NAME): $(SRCS) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)
	@echo "\033[1;32m[ ✔ ] $(NAME) ready!\033[0m"

# Build minilibx-linux library
$(MLX): $(MLX_DIR)
	@rm -rf minilibx-linux/.git
	@make -C $^ > /dev/null 2>&1

$(MLX_DIR):
	@echo "\033[1;35m[ ✔ ] Preparing minilibx...\033[0m"
	@git clone https://github.com/42Paris/minilibx-linux.git > /dev/null 2>&1

# Compiling object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[1;36m[ ✔ ] Compiling objects...\033[0m"

clean:
	@rm -rf $(OBJS)
	@echo "\033[1;31m[ ✔ ] Object files removed\033[0m"

fclean: clean
	@rm -rf $(NAME) $(MLX_DIR)
	@echo "\033[1;31m[ ✔ ] Executable and Minilibx removed\033[0m"

re: fclean all

# Declare these targets as .PHONY so they are not treated as files
.PHONY: all clean fclean re
