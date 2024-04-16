/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:16:38 by ismirand          #+#    #+#             */
/*   Updated: 2024/04/16 15:22:31 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_keys(int key, t_game *game)
{
	if (key == ESC)
		exit_game(game, 1);
	if (key == UP || key == KEY_W)
		move_up(game);
	if (key == DOWN || key == KEY_S)
		move_down(game);
	if (key == LEFT || key == KEY_A)
		move_left(game);
	if (key == RIGHT || key == KEY_D)
		move_right(game);
	return (0);
}
//altera: posição do player, numero no mapa, imagens
//se for C, diminuir game->collectables
//tem sempre que checar se nao é 1
//so pode chegar no E. se game->collectables == 0
//printar quantidade de movimentos, e saida (?)
//mlx_put_string = printa no jogo (BONUS) (apagar e printar dnv)


void	put_images_on_window(t_game *game)
{
	int	height;
	int	width;

	height = -1;
	while (game->map[++height])
	{
		width = -1;
		while (game->map[height][++width])
		{
			if (game->map[height][width] == '0')
				mlx_put_image_to_window(game->mlx, game->window, game->ground, width * SZ, height * SZ);
			if (game->map[height][width] == '1')
				mlx_put_image_to_window(game->mlx, game->window, game->wall, width * SZ, height * SZ);
			if (game->map[height][width] == 'P')
				mlx_put_image_to_window(game->mlx, game->window, game->player, width * SZ, height * SZ);
			if (game->map[height][width] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, game->c1, width * SZ, height * SZ);
			if (game->map[height][width] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, game->exit, width * SZ, height * SZ);
		}
	}
}

void	set_images_to_pointer(t_game *game, int i)
{
	game->ground = mlx_xpm_file_to_image(game->mlx, "img/ground.xpm", &i, &i);
	game->wall = mlx_xpm_file_to_image(game->mlx, "img/wall.xpm", &i, &i);
	game->player = mlx_xpm_file_to_image(game->mlx, "img/player.xpm", &i, &i);
	game->p_right = mlx_xpm_file_to_image(game->mlx, "img/p_right.xpm", &i, &i);
	game->p_left = mlx_xpm_file_to_image(game->mlx, "img/p_left.xpm", &i, &i);
	game->p_up = mlx_xpm_file_to_image(game->mlx, "img/p_up.xpm", &i, &i);
	game->p_down = mlx_xpm_file_to_image(game->mlx, "img/p_down.xpm", &i, &i);
	game->p_exit = mlx_xpm_file_to_image(game->mlx, "img/p_exit.xpm", &i, &i);
	game->c1 = mlx_xpm_file_to_image(game->mlx, "img/c1.xpm", &i, &i);
	game->c2 = mlx_xpm_file_to_image(game->mlx, "img/c2.xpm", &i, &i);
	game->c3 = mlx_xpm_file_to_image(game->mlx, "img/c3.xpm", &i, &i);
	game->c4 = mlx_xpm_file_to_image(game->mlx, "img/c4.xpm", &i, &i);
	game->exit = mlx_xpm_file_to_image(game->mlx, "img/exit.xpm", &i, &i);
}
