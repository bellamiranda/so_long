/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:12:05 by ismirand          #+#    #+#             */
/*   Updated: 2024/04/26 16:15:29 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

//max number of random values (NOT WORKING)
# ifndef RAND_MAX
#  define RAND_MAX 3
# endif

# include <unistd.h>//read, write
# include <stdio.h>//error
# include <string.h>//strerror
# include <fcntl.h>//open
# include <stdlib.h>//malloc, free, exit + rand
# include "minilibx-linux/mlx_int.h"
# include "minilibx-linux/mlx.h"

# define UP 65362 //key codes
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define ESC 65307

# define SZ 45 //size of the images

typedef struct	s_cord
{
	int	x;
	int	y;
}		t_cord;

typedef struct	s_game
{
	void	*mlx;//faz a conexão do programa com a minilibx
	void	*wd;//pointer que leva ate a janela
	int		height;
	int		width;
	int		x;
	int		y;
	int		collectables;
	int		path_c;
	int		p_y;
	int		p_x;
	int		movements;
	char	**map;
	void	*player;
	void	*p_right;
	void	*p_left;
	void	*p_up;
	void	*p_down;
	void	*p_exit;
	void	*c1;
	void	*c2;
	void	*c3;
	void	*c4;
	void	*ground;
	void	*wall;
	void	*exit;
	void	*enemy;
	int		was_exit;
	t_cord	*coins;
	int		enemies_count;
	t_cord	*enemies;
}			t_game;


//get_next_line
char	*ft_strjoin(char *s1, char *s2);
char	*get_ret(char *str);
int		freefree(char *str);
char	*save_line(char *str);
char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strlen(char *str);
int		newline(char *str);
char	*ft_clean(char **s1, char **s2);

//utils
int		find_ber(char *map, char *cmp);
char	*ft_strdup(char *s);
char	**ft_mtxdup(t_game *game);
int		flood_fill(char **map, int x, int y);
int		flood_fill_c(char **map, int x, int y);
void	ft_putnbr_fd(int n, int fd);
void	write_movements(t_game *game);

//map
void	map_init(t_game **game, char *arg);
void	map_lines(t_game *game, char *arg);
void	map_validations(t_game *game);
int		invalid_char(t_game *game);
int		double_char(t_game *game);
int		miss_walls(t_game *game);
int		min_area(t_game *game);
int		not_rectangular(t_game *game);
int		valid_path_exit(t_game *game);
int		valid_path_collectable(t_game *game);
int		ft_aux(t_game *game, char ***map, int x, int y);

//game
void	set_images_to_pointer(t_game *game, int i);
void	put_images_on_window(t_game *game);
int		put_keys(int key, t_game *game);
void	move_up(t_game *game);
void	aux_move_up(t_game *game, int flag);
void	move_left(t_game *game);
void	aux_move_left(t_game *game, int flag);
void	move_down(t_game *game);
void	aux_move_down(t_game *game, int flag);
void	move_right(t_game *game);
void	aux_move_right(t_game *game, int flag);
void	find_collectable(t_game *game);
int		coin_spin(t_game *game);
void	coin_image(t_game *g, int flag);

//free
void	free_struct(t_game *game);
void	free_mtx(char **src);
int		exit_game(t_game *game, int flag);
void	clean_mlx(t_game *game);

//bonus
void	write_movements_on_window(t_game *game);
char	*ft_itoa(int n);
void	find_enemy(t_game *game);
void	random_enemy(t_game *game);
void	enemy_move_up(t_game *g);
void	enemy_move_down(t_game *g);
void	enemy_move_right(t_game *g);
void	enemy_move_left(t_game *g);

#endif

//GIMP - programa de tratamento de imagens 
	//corta em png e coloca o chão atras