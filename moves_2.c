/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:49:47 by ismirand          #+#    #+#             */
/*   Updated: 2024/05/06 19:23:26 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	aux_move_right(t_game *game, int flag)
{
	if (game->was_exit == 1)
	{
		mlx_put_image_to_window(game->mlx, game->wd, game->exit,
			game->p_x * SZ, game->p_y * SZ);
		game->was_exit = 0;
		game->map[game->p_y][game->p_x] = 'E';
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->wd, game->ground,
			game->p_x * SZ, game->p_y * SZ);
		game->map[game->p_y][game->p_x] = '0';
	}
	if (flag == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->wd, game->p_exit,
			(game->p_x + 1) * SZ, game->p_y * SZ);
		game->was_exit = 1;
	}
	if (flag == '0' || flag == 'C')
		mlx_put_image_to_window(game->mlx, game->wd, game->p_right,
			(game->p_x + 1) * SZ, game->p_y * SZ);
	game->map[game->p_y][game->p_x + 1] = 'P';
	if (flag == 'C')
		game->collectables--;
}

void	move_right(t_game *game)
{
	if (game->map[game->p_y][game->p_x + 1] == '1')
		return ;
	if (game->map[game->p_y][game->p_x + 1] == '0')
		aux_move_right(game, '0');
	else if (game->map[game->p_y][game->p_x + 1] == 'E')
	{
		aux_move_right(game, 'E');
		if (game->collectables == 0)
			exit_game(game, 0);
	}
	else if (game->map[game->p_y][game->p_x + 1] == 'C')
	{
		aux_move_right(game, 'C');
		free (game->coins);
		find_collectable(game);
	}
	else if (game->map[game->p_y][game->p_x + 1] == 'T')
		exit_game(game, 2);
	game->p_x++;
	game->movements++;
	write_movements(game);
}

void	aux_move_left(t_game *game, int flag)
{
	if (game->was_exit == 1)
	{
		mlx_put_image_to_window(game->mlx, game->wd, game->exit,
			game->p_x * SZ, game->p_y * SZ);
		game->was_exit = 0;
		game->map[game->p_y][game->p_x] = 'E';
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->wd, game->ground,
			game->p_x * SZ, game->p_y * SZ);
		game->map[game->p_y][game->p_x] = '0';
	}
	if (flag == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->wd, game->p_exit,
			(game->p_x - 1) * SZ, game->p_y * SZ);
		game->was_exit = 1;
	}
	if (flag == '0' || flag == 'C')
		mlx_put_image_to_window(game->mlx, game->wd, game->p_left,
			(game->p_x - 1) * SZ, game->p_y * SZ);
	game->map[game->p_y][game->p_x - 1] = 'P';
	if (flag == 'C')
		game->collectables--;
}

void	move_left(t_game *game)
{
	if (game->map[game->p_y][game->p_x - 1] == '1')
		return ;
	if (game->map[game->p_y][game->p_x - 1] == '0')
		aux_move_left(game, '0');
	else if (game->map[game->p_y][game->p_x - 1] == 'E')
	{
		aux_move_left(game, 'E');
		if (game->collectables == 0)
			exit_game(game, 0);
	}
	else if (game->map[game->p_y][game->p_x - 1] == 'C')
	{
		aux_move_left(game, 'C');
		free (game->coins);
		find_collectable(game);
	}
	else if (game->map[game->p_y][game->p_x - 1] == 'T')
		exit_game(game, 2);
	game->p_x--;
	game->movements++;
	write_movements(game);
}
