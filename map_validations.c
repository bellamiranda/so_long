/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:11:39 by ismirand          #+#    #+#             */
/*   Updated: 2024/04/15 21:06:25 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	not_rectangular(t_game *game)
{
	int	i;
	int	cur_line;
	int	first_line;

	i = -1;
	while (game->map[++i])
	{
		cur_line = -1;
		while (game->map[i][++cur_line])
			continue ;
		if (i == 0)
		{
			game->width = cur_line;
			first_line = cur_line;
		}
		if (first_line != cur_line)
			return (write (2, "Error\nMap not rectangular\n", 27));
	}
	return (0);
}

int	min_area(t_game *game)
{
	int	i;

	i = -1;
	while (game->map[0][++i])
		continue ;
	i += game->height;
	if (i < 8)
		return (write (2, "Error\nMap is too small\n", 24));
	return (0);
}

int	miss_walls(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		if (i == 0 || i == game->height - 1)
			while (game->map[i][++j])
				if (game->map[i][j] != '1')
					return (write (2, "Error\nMap not closed by walls\n", 31));
		j = -1;
		while (game->map[i][++j])
			continue ;
		if (game->map[i][0] != '1' || game->map[i][j - 1] != '1')
			return (write (2, "Error\nMap not closed by walls\n", 31));
	}
	return (0);
}

int	double_char(t_game *game)
{
	int	y;
	int	x;
	int	count;

	count = 0;
	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'P')
			{
				game->p_y = y;
				game->p_x = x;
				count++;
			}
			if (game->map[y][x] == 'E')
				count++;
		}
	}
	if (count != 2)
		return (write (2, "Error\nMap is missing player or exit\n", 37));
	return (0);
}

int	invalid_char(t_game *game)
{
	int	i;
	int	j;
	int	c;

	c = 0;
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1' &&
				game->map[i][j] != 'P' && game->map[i][j] != 'C' &&
				game->map[i][j] != 'E')
				return (write (2, "Error\nMap has invalid character\n", 32));
			if (game->map[i][j] == 'C')
				c++;
		}
	}
	game->collectables = c;
	if (c == 0)
		return (write (2, "Error\nMap doesn't have collectables\n", 36));
	return (0);
}
