NAME = so_long

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

LIB = -Lminilibx-linux -lmlx -lXext -lX11 -lm 
MINILIBX = minilibx-linux/libmlx_linux.a
MLX = minilibx-linux

SRCS = get_next_line.c get_next_line_utils.c \
		utils.c map.c map_validations.c free.c \
		valid_paths.c game.c moves.c moves_2.c \
		bonus.c bonus_moves.c 

OBJS = $(SRCS:.c=.o)

RM = rm -rf

all: $(MLX) $(MINILIBX) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) main.c $(LIB) -o $(NAME) 

$(MINILIBX): $(MLX)
	$(RM) minilibx-linux/.git
	@make -C $^

$(MLX):
	@git clone https://github.com/42Paris/minilibx-linux.git

#	$(CC) $(CFLAGS) $(NAME) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS) $(MLX)

re: fclean all
