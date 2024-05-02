/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:57:31 by ismirand          #+#    #+#             */
/*   Updated: 2024/05/01 20:15:53 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	random_enemy(t_game *game)
{
	int			flag;
	static int	i = -1; //to make it move slowly

	find_enemy(game);
	//ACHAR UM LUGAR PRA DAR FREE
	if (!game->enemies_count)
		return ;
	if (++i == 10000)
	{
		flag = rand();
		if (flag % 4 == 0)
			enemy_move_up(game);
		if (flag % 4 == 1)
			enemy_move_down(game);
		if (flag % 4 == 2)
			enemy_move_left(game);
		if (flag % 4 == 3)
			enemy_move_right(game);
		i = -1;
	}
	free (game->enemies);
}

void	find_enemy(t_game *game)
{
	int	x;
	int	y;
	int	position;
	t_cord	*enemies;

	enemies = ft_calloc(sizeof(t_cord), game->enemies_count);
	game->enemies = enemies;
	position = 0;
	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'T')
			{
				game->enemies[position].x = x;
				game->enemies[position].y = y;
				position++;
			}
		}
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		nb;

	nb = n;
	len = 1;
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (n >= 10)
	{
		str[--len] = n % 10 + '0';
		n /= 10;
	}
	str[--len] = n + '0';
	return (str);
}

void	write_movements_on_window(t_game *game)
{
	char	*movements;

	movements = ft_itoa(game->movements);
	mlx_put_image_to_window(game->mlx, game->wd, game->wall, 85, 0);
	mlx_string_put(game->mlx, game->wd, 35, 20, 0x000000, "MOVEMENTS: ");
	mlx_string_put(game->mlx, game->wd, 100, 20, 0x000000, movements);
	free(movements);
}
