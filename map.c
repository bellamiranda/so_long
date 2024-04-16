/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:30:49 by ismirand          #+#    #+#             */
/*   Updated: 2024/04/10 20:08:36 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_validations(t_game *game)
{
	if (invalid_char(game) || double_char(game) || miss_walls(game)
		|| min_area(game) || not_rectangular(game)
		|| !valid_path_exit(game) || !valid_path_collectable(game))
	{
		free_struct(game);
		exit (1);
	}
}

void	map_lines(t_game *game, char *arg)
{
	char	*line;
	int		fd;

	(game)->height = 0;
	fd = open(arg, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		(game)->height++;
		free (line);
	}
	//free (line);
	close(fd);
}

void	map_init(t_game **game, char *arg)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	*game = malloc(sizeof(t_game));
	fd = open(arg, O_RDONLY);
	map_lines(*game, arg);
	(*game)->map = ft_calloc(sizeof(char *), (*game)->height + 1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		(*game)->map[i++] = ft_strdup(line);
		free (line);
	}
	//(*game)->map[i] = '\0';
	free (line);
}
