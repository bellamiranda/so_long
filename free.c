/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:22:14 by ismirand          #+#    #+#             */
/*   Updated: 2024/03/12 14:29:44 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	while (++i <= game->lines)
		free (game->map[i]);
	free (game->map);
	free (game);
}
