/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:20:13 by ismirand          #+#    #+#             */
/*   Updated: 2024/04/16 15:17:09 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	aux_move_down(t_game *game, int flag)
{
	if (game->was_exit == 1)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->exit, 
			game->p_x * SZ, game->p_y * SZ);
		game->was_exit = 0;
	}
	else
		mlx_put_image_to_window(game->mlx, game->window, game->ground, 
			game->p_x * SZ, game->p_y * SZ);
	if (flag == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->window, game->p_exit,
			game->p_x * SZ, (game->p_y + 1) * SZ);
		game->was_exit = 1;
	}
	if (flag == '0' || flag == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->p_down, 
			game->p_x * SZ, (game->p_y + 1) * SZ);
	game->p_y++;
	if (flag == 'C')
		game->collectables--;
}

void	move_down(t_game *game)
{
	if (game->map[game->p_y + 1][game->p_x] == '1')
		return ;
	if (game->map[game->p_y + 1][game->p_x] == '0' || game->map[game->p_y + 1][game->p_x] == 'P')
		aux_move_down(game, '0');
	else if (game->map[game->p_y + 1][game->p_x] == 'E')
	{
		aux_move_down(game, 'E');
		if (game->collectables == 0)
			exit_game(game, 0);
	}
	else if (game->map[game->p_y + 1][game->p_x] == 'C')
	{
		aux_move_down(game, 'C');
		game->map[game->p_y][game->p_x] = '0';
	}
	game->movements++;
	write_movements(game);
}

void	aux_move_up(t_game *game, int flag)
{
	if (game->was_exit == 1)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->exit, 
			game->p_x * SZ, game->p_y * SZ);
		game->was_exit = 0;
	}
	else
		mlx_put_image_to_window(game->mlx, game->window, game->ground, 
			game->p_x * SZ, game->p_y * SZ);
	if (flag == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->window, game->p_exit,
			game->p_x * SZ, (game->p_y - 1) * SZ);
		game->was_exit = 1;
	}
	if (flag == '0' || flag == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->p_up, 
			game->p_x * SZ, (game->p_y - 1) * SZ);
	game->p_y--;
	if (flag == 'C')
		game->collectables--;
}

void	move_up(t_game *game)
{
	if (game->map[game->p_y - 1][game->p_x] == '1')
		return ;
	if (game->map[game->p_y - 1][game->p_x] == '0' || game->map[game->p_y - 1][game->p_x] == 'P')
		aux_move_up(game, '0');
	else if (game->map[game->p_y - 1][game->p_x] == 'E')
	{
		aux_move_up(game, 'E');
		if (game->collectables == 0)
		{
			sleep(1);
			exit_game(game, 0);
		}
	}
	else if (game->map[game->p_y - 1][game->p_x] == 'C')
	{
		aux_move_up(game, 'C');
		game->map[game->p_y][game->p_x] = '0';
	}
	game->movements++;
	write_movements(game);
}
