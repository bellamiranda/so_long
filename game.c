/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:16:38 by ismirand          #+#    #+#             */
/*   Updated: 2024/05/02 20:44:46 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_collectable(t_game *game)
{
	int		x;
	int		y;
	int		position;
	t_cord	*coins;

	coins = ft_calloc(sizeof(t_cord), game->collectables);
	game->coins = coins;
	position = 0;
	x = -1;
	while (game->map[++x])
	{
		y = -1;
		while (game->map[x][++y])
		{
			if (game->map[x][y] == 'C')
			{
				game->coins[position].x = x;
				game->coins[position].y = y;
				position++;
			}
			if (position == game->collectables)
				break ;
		}
	}
}

void	coin_image(t_game *g, int flag)
{
	int	p;

	p = -1;
	while (++p < g->collectables)
	{
		if (flag == 1)
			mlx_put_image_to_window(g->mlx, g->wd, g->c1,
				g->coins[p].y * SZ, g->coins[p].x * SZ);
		if (flag == 2)
			mlx_put_image_to_window(g->mlx, g->wd, g->c2,
				g->coins[p].y * SZ, g->coins[p].x * SZ);
		if (flag == 3)
			mlx_put_image_to_window(g->mlx, g->wd, g->c3,
				g->coins[p].y * SZ, g->coins[p].x * SZ);
		if (flag == 4)
			mlx_put_image_to_window(g->mlx, g->wd, g->c4,
				g->coins[p].y * SZ, g->coins[p].x * SZ);
		if (g->coins[p].y == 0 && g->coins[p].x == 0)
			mlx_put_image_to_window(g->mlx, g->wd, g->wall,
				g->coins[p].y * SZ, g->coins[p].x * SZ);
	}
}

int	coin_spin(t_game *g)
{
	static int	i = -1;

	random_enemy(g);
	if (++i == 0)
		coin_image(g, 1);
	if (i == 10000)
		coin_image(g, 2);
	if (i == 20000)
		coin_image(g, 3);
	if (i == 30000)
	{
		coin_image(g, 4);
		i = -1;
	}
	return (0);
}

void	put_images_on_window(t_game *g)
{
	int	x;
	int	y;

	x = -1;
	while (g->map[++x])
	{
		y = -1;
		while (g->map[x][++y])
		{
			if (g->map[x][y] == '0')
				mlx_put_image_to_window(g->mlx, g->wd, g->ground,
					y * SZ, x * SZ);
			if (g->map[x][y] == '1')
				mlx_put_image_to_window(g->mlx, g->wd, g->wall, y * SZ, x * SZ);
			if (g->map[x][y] == 'P')
				mlx_put_image_to_window(g->mlx, g->wd, g->player,
					y * SZ, x * SZ);
			if (g->map[x][y] == 'C')
				mlx_put_image_to_window(g->mlx, g->wd, g->c1, y * SZ, x * SZ);
			if (g->map[x][y] == 'E')
				mlx_put_image_to_window(g->mlx, g->wd, g->exit, y * SZ, x * SZ);
			if (g->map[x][y] == 'T')
				mlx_put_image_to_window(g->mlx, g->wd, g->t, y * SZ, x * SZ);
		}
	}
}

void	set_images_to_pointer(t_game *g, int i)
{
	g->ground = mlx_xpm_file_to_image(g->mlx, "img/ground.xpm", &i, &i);
	g->wall = mlx_xpm_file_to_image(g->mlx, "img/wall.xpm", &i, &i);
	g->player = mlx_xpm_file_to_image(g->mlx, "img/player.xpm", &i, &i);
	g->p_right = mlx_xpm_file_to_image(g->mlx, "img/p_right.xpm", &i, &i);
	g->p_left = mlx_xpm_file_to_image(g->mlx, "img/p_left.xpm", &i, &i);
	g->p_up = mlx_xpm_file_to_image(g->mlx, "img/p_up.xpm", &i, &i);
	g->p_down = mlx_xpm_file_to_image(g->mlx, "img/p_down.xpm", &i, &i);
	g->p_exit = mlx_xpm_file_to_image(g->mlx, "img/p_exit.xpm", &i, &i);
	g->c1 = mlx_xpm_file_to_image(g->mlx, "img/c1.xpm", &i, &i);
	g->c2 = mlx_xpm_file_to_image(g->mlx, "img/c2.xpm", &i, &i);
	g->c3 = mlx_xpm_file_to_image(g->mlx, "img/c3.xpm", &i, &i);
	g->c4 = mlx_xpm_file_to_image(g->mlx, "img/c4.xpm", &i, &i);
	g->exit = mlx_xpm_file_to_image(g->mlx, "img/exit.xpm", &i, &i);
	g->t = mlx_xpm_file_to_image(g->mlx, "img/enemy.xpm", &i, &i);
}
