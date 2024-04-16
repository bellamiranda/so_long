/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:22:14 by ismirand          #+#    #+#             */
/*   Updated: 2024/04/16 14:45:52 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_game *game, int flag)
{
	mlx_destroy_image(game->mlx, game->ground);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->c1);
	mlx_destroy_image(game->mlx, game->c2);
	mlx_destroy_image(game->mlx, game->c3);
	mlx_destroy_image(game->mlx, game->c4);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->p_right);
	mlx_destroy_image(game->mlx, game->p_left);
	mlx_destroy_image(game->mlx, game->p_up);
	mlx_destroy_image(game->mlx, game->p_down);
	mlx_destroy_image(game->mlx, game->p_exit);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_struct(game);
	exit (flag);
}

void	free_mtx(char **src)
{
	int	i;

	i = -1;
	while (src[++i])
		free (src[i]);
	free (src);
}

void	free_struct(t_game *game)
{
	int	i;

	i = -1;
	while (++i <= game->height)
		free (game->map[i]);
	free (game->map);
	free (game);
}
