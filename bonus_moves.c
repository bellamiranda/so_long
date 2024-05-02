/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:54:30 by ismirand          #+#    #+#             */
/*   Updated: 2024/05/01 20:25:10 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_move_up(t_game *g)
{
	int	a;

	a = rand() % g->enemies_count;
	if (g->map[g->enemies[a].y - 1][g->enemies[a].x] == '1'
		|| g->map[g->enemies[a].y - 1][g->enemies[a].x] == 'C'
		|| g->map[g->enemies[a].y - 1][g->enemies[a].x] == 'E')
		return ;
	if (g->map[g->enemies[a].y - 1][g->enemies[a].x] == 'P')
		exit_game(g, 3);
	if (g->map[g->enemies[a].y - 1][g->enemies[a].x] == '0')
	{
		g->map[g->enemies[a].y][g->enemies[a].x] = '0';
		mlx_put_image_to_window(g->mlx, g->wd, g->ground,
			g->enemies[a].x * SZ, g->enemies[a].y * SZ);
		g->enemies[a].y--;
		g->map[g->enemies[a].y][g->enemies[a].x] = 'T';
		mlx_put_image_to_window(g->mlx, g->wd, g->enemy,
			g->enemies[a].x * SZ, g->enemies[a].y * SZ);
	}
}

void	enemy_move_down(t_game *g)
{
	int	a;

	a = rand() % g->enemies_count;
	if (g->map[g->enemies[a].y + 1][g->enemies[a].x] == '1'
		|| g->map[g->enemies[a].y + 1][g->enemies[a].x] == 'C'
		|| g->map[g->enemies[a].y + 1][g->enemies[a].x] == 'E')
		return ;
	if (g->map[g->enemies[a].y + 1][g->enemies[a].x] == 'P')
		exit_game(g, 3);
	if (g->map[g->enemies[a].y + 1][g->enemies[a].x] == '0')
	{
		g->map[g->enemies[a].y][g->enemies[a].x] = '0';
		mlx_put_image_to_window(g->mlx, g->wd, g->ground,
			g->enemies[a].x * SZ, g->enemies[a].y * SZ);
		g->enemies[a].y++;
		g->map[g->enemies[a].y][g->enemies[a].x] = 'T';
		mlx_put_image_to_window(g->mlx, g->wd, g->enemy,
			g->enemies[a].x * SZ, g->enemies[a].y * SZ);
	}
}

void	enemy_move_right(t_game *g)
{
	int	a;

	a = rand() % g->enemies_count;
	if (g->map[g->enemies[a].y][g->enemies[a].x + 1] == '1'
		|| g->map[g->enemies[a].y][g->enemies[a].x + 1] == 'C'
		|| g->map[g->enemies[a].y][g->enemies[a].x + 1] == 'E')
		return ;
	if (g->map[g->enemies[a].y][g->enemies[a].x + 1] == 'P')
		exit_game(g, 3);
	if (g->map[g->enemies[a].y][g->enemies[a].x + 1] == '0')
	{
		g->map[g->enemies[a].y][g->enemies[a].x] = '0';
		mlx_put_image_to_window(g->mlx, g->wd, g->ground,
			g->enemies[a].x * SZ, g->enemies[a].y * SZ);
		g->enemies[a].x++;
		g->map[g->enemies[a].y][g->enemies[a].x] = 'T';
		mlx_put_image_to_window(g->mlx, g->wd, g->enemy,
			g->enemies[a].x * SZ, g->enemies[a].y * SZ);
	}
}

void	enemy_move_left(t_game *g)
{
	int	a;

	a = rand() % g->enemies_count;
	if (g->map[g->enemies[a].y][g->enemies[a].x - 1] == '1'
		|| g->map[g->enemies[a].y][g->enemies[a].x - 1] == 'C'
		|| g->map[g->enemies[a].y][g->enemies[a].x - 1] == 'E')
		return ;
	if (g->map[g->enemies[a].y][g->enemies[a].x - 1] == 'P')
		exit_game(g, 3);
	if (g->map[g->enemies[a].y][g->enemies[a].x - 1] == '0')
	{
		g->map[g->enemies[a].y][g->enemies[a].x] = '0';
		mlx_put_image_to_window(g->mlx, g->wd, g->ground,
			g->enemies[a].x * SZ, g->enemies[a].y * SZ);
		g->enemies[a].x--;
		g->map[g->enemies[a].y][g->enemies[a].x] = 'T';
		mlx_put_image_to_window(g->mlx, g->wd, g->enemy,
			g->enemies[a].x * SZ, g->enemies[a].y * SZ);
	}
}
