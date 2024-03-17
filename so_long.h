/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:12:05 by ismirand          #+#    #+#             */
/*   Updated: 2024/03/12 15:07:49 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include "minilibx-linux/mlx_int.h"
# include "minilibx-linux/mlx.h"

typedef struct s_game
{
	void	*library;//faz a conexão do programa com a minilibx
	void	*window;//pointer que leva ate a janela
	int		lines;
	int		collectables;
	int		path_c;
	char	**map;
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

//free
void	free_struct(t_game *game);
void	free_mtx(char **src);

#endif

//GIMP - programa de tratamento de imagens 
	//corta em png e coloca o chão atras