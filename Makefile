NAME = so_long

CC = cc 
CFLAGS = -Wall -Werror -Wextra -g
MLX_DIR = minilibx-linux/
MLX_FLAGS = -L $(MLX_DIR) -lm -lmlx -Ilmlx -lXext -lX11

SRCS = get_next_line.c get_next_line_utils.c \
		utils.c map.c map_validations.c free.c \
		valid_paths.c game.c moves.c moves_2.c \
		bonus.c

OBJS = $(SRCS:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) main.c $(MLX_FLAGS) -o $(NAME) 

#	$(CC) $(CFLAGS) $(NAME) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all



bonus: $(NAME) $(NAME_BONUS)

$(NAME_BONUS): $(OBJS) $(OBJS_BONUS)
	ar -rcs $(NAME_BONUS) $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $@ $^
