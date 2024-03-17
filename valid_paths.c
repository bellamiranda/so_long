/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:32:04 by ismirand          #+#    #+#             */
/*   Updated: 2024/03/12 15:27:30 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//achar todos os C antes de chegar no E
int	flood_fill_c(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return (0);
	if (map[y][x] == '0' || map[y][x] == 'C')
		map[y][x] = 'X';
	if (map[y][x] == 'P')
		return (1);
	if (flood_fill_c(map, x, y + 1) == 1 || flood_fill_c(map, x, y - 1) == 1
		|| flood_fill_c(map, x + 1, y) == 1 || flood_fill_c(map, x - 1, y) == 1)
		return (1);
	return (0);
}

//return 1 if E is found
// return 2 if 1 C is found
int	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return (0);
	if (map[y][x] == '0' || map[y][x] == 'C')
		map[y][x] = 'X';
	if (map[y][x] == 'E')
		return (1);
	if (flood_fill(map, x, y + 1) == 1 || flood_fill(map, x, y - 1) == 1
		|| flood_fill(map, x + 1, y) == 1 || flood_fill(map, x - 1, y) == 1)
		return (1);
	return (0);
}

int	ft_aux(t_game *game, char ***map, int x, int y)
{
	int	ret;

	ret = flood_fill_c(*map, x, y);
	game->path_c++;
	free_mtx (*map);
	*map = ft_mtxdup(game);
	return (ret);
}

int	valid_path_collectable(t_game *game)
{
	char	**map;
	int		y;
	int		x;
	int		ret;

	y = -1;
	ret = 1;
	map = ft_mtxdup(game);
	game->path_c = 0;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x] && game->path_c < game->collectables)
		{
			if (map[y][x] == 'C')
				ret = ft_aux(game, &map, x, y);
			if (ret == 0)
			{
				write (2, "Error\nMap doesn't have valid path to C\n", 40);
				return (free_mtx(map), 0);
			}
		}
	}
	return (free_mtx(map), ret);
}

int	valid_path_exit(t_game *game)
{
	char	**map;
	int		y;
	int		x;
	int		ret;

	y = -1;
	map = ft_mtxdup(game);
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] == 'P')
				ret = flood_fill(map, x, y);
	}
	free_mtx(map);
	if (!ret)
		write (2, "Error\nMap doesn't have valid path to Exit\n", 43);
	return (ret);
}
