/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:57:31 by ismirand          #+#    #+#             */
/*   Updated: 2024/04/23 17:26:36 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_enemy(t_game *game)
{
	static int	x;
	static int	y;

	x = -1;
	while (game->map[++x])
	{
		y = -1;
		while (game->map[x][++y])
		{
			if (game->map[x][y] == 'T')
			{
				game->x = x;
				game->y = y;
				//enemy_move(game);
			}
		}
	}
	return (0);
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
	mlx_put_image_to_window(game->mlx, game->wd, game->wall, 75, 0);
	mlx_string_put(game->mlx, game->wd, 30, 20, 0x000000, "MOVEMENTS: ");
	mlx_string_put(game->mlx, game->wd, 95, 20, 0x000000, movements);
	free(movements);
}
