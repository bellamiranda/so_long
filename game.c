/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:16:38 by ismirand          #+#    #+#             */
/*   Updated: 2024/04/23 17:26:45 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_keys(int key, t_game *g)
{
	if (key == ESC)
		exit_game(g, 1);
	if (key == UP || key == KEY_W)
		move_up(g);
	if (key == DOWN || key == KEY_S)
		move_down(g);
	if (key == LEFT || key == KEY_A)
		move_left(g);
	if (key == RIGHT || key == KEY_D)
		move_right(g);
	return (0);
}
//altera: posição do player, numero no mapa, imagens
//se for C, diminuir g->collectables
//tem sempre que checar se nao é 1
//so pode chegar no E. se g->collectables == 0
//printar quantidade de movimentos, e saida (?)
//mlx_put_string = printa no jogo (BONUS) (apagar e printar dnv)

int	find_collectable(t_game *game)
{
	static int	x;
	static int	y;

	x = -1;
	while (game->map[++x])
	{
		y = -1;
		while (game->map[x][++y])
		{
			if (game->map[x][y] == 'C')
			{
				game->x = x;
				game->y = y;
				coin_spin(game);
			}
		}
	}
	return (0);
}

int	coin_spin(t_game *g)
{
	static int	i = -1;

	if (++i == 0)
		mlx_put_image_to_window(g->mlx, g->wd, g->c1, g->y * SZ, g->x * SZ);
	if (i == 10000)
		mlx_put_image_to_window(g->mlx, g->wd, g->c2, g->y * SZ, g->x * SZ);
	if (i == 20000)
		mlx_put_image_to_window(g->mlx, g->wd, g->c3, g->y * SZ, g->x * SZ);
	if (i == 30000)
	{
		mlx_put_image_to_window(g->mlx, g->wd, g->c4, g->y * SZ, g->x * SZ);
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
				mlx_put_image_to_window(g->mlx, g->wd, g->enemy, y * SZ, x * SZ);
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
	g->enemy = mlx_xpm_file_to_image(g->mlx, "img/enemy.xpm", &i, &i);
}
