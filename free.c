/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:22:14 by ismirand          #+#    #+#             */
/*   Updated: 2024/05/01 20:24:36 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_mlx(t_game *game)
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
	mlx_destroy_image(game->mlx, game->enemy);
	mlx_destroy_window(game->mlx, game->wd);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

int	exit_game(t_game *game, int flag)
{
	if (flag == 0)
	{
		game->movements++;
		write_movements(game);
		write (1, "!!!CONGRATS, YOU WIN!!!\n", 25);
	}
	if (flag == 1)
		write (1, "!!!GAME OVER!!!\n", 16);
	if (flag == 2)
		write (1, "!!!DON'T TOUCH THE ENEMY!!!\n", 29);
	if (flag == 3)
	{
		free (game->enemies);
		write (1, "!!!ENEMY KILLED YOU!!!\n", 24);
	}
	clean_mlx(game);
	free_struct(game);
	exit (flag);
	return (0);
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
	free (game->coins);
/* 	if (game->enemies_count > 0 && game->enemies)
		free (game->enemies); */
	while (++i <= game->height)
		free (game->map[i]);
	free (game->map);
	free (game);
}
