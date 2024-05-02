/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:20:13 by ismirand          #+#    #+#             */
/*   Updated: 2024/05/02 20:50:42 by ismirand         ###   ########.fr       */
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

void	aux_move_down(t_game *game, int flag)
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
			game->p_x * SZ, (game->p_y + 1) * SZ);
		game->was_exit = 1;
	}
	if (flag == '0' || flag == 'C')
		mlx_put_image_to_window(game->mlx, game->wd, game->p_down,
			game->p_x * SZ, (game->p_y + 1) * SZ);
	game->map[game->p_y + 1][game->p_x] = 'P';
	if (flag == 'C')
		game->collectables--;
}

void	move_down(t_game *game)
{
	if (game->map[game->p_y + 1][game->p_x] == '1')
		return ;
	if (game->map[game->p_y + 1][game->p_x] == '0')
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
		free (game->coins);
		find_collectable(game);
	}
	else if (game->map[game->p_y + 1][game->p_x] == 'T')
		exit_game(game, 2);
	game->p_y++;
	game->movements++;
	write_movements(game);
}

void	aux_move_up(t_game *game, int flag)
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
			game->p_x * SZ, (game->p_y - 1) * SZ);
		game->was_exit = 1;
	}
	if (flag == '0' || flag == 'C')
		mlx_put_image_to_window(game->mlx, game->wd, game->p_up,
			game->p_x * SZ, (game->p_y - 1) * SZ);
	game->map[game->p_y - 1][game->p_x] = 'P';
	if (flag == 'C')
		game->collectables--;
}

void	move_up(t_game *game)
{
	if (game->map[game->p_y - 1][game->p_x] == '1')
		return ;
	if (game->map[game->p_y - 1][game->p_x] == '0')
		aux_move_up(game, '0');
	else if (game->map[game->p_y - 1][game->p_x] == 'E')
	{
		aux_move_up(game, 'E');
		if (game->collectables == 0)
			exit_game(game, 0);
	}
	else if (game->map[game->p_y - 1][game->p_x] == 'C')
	{
		aux_move_up(game, 'C');
		game->map[game->p_y][game->p_x] = '0';
		free (game->coins);
		find_collectable(game);
	}
	else if (game->map[game->p_y - 1][game->p_x] == 'T')
		exit_game(game, 2);
	game->p_y--;
	game->movements++;
	write_movements(game);
}
