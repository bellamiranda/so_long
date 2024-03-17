/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:15:06 by ismirand          #+#    #+#             */
/*   Updated: 2024/03/12 14:35:17 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_mtxdup(t_game *game)
{
	char **dest;
	int	i;

	i = -1;
	dest = ft_calloc(sizeof(char *), game->lines + 1);
	if (!dest)
		return (NULL);
	while (game->map[++i])
		dest[i] = ft_strdup(game->map[i]);
	return (dest);
}

int	find_ber(char *map, char *cmp)
{
	int	size;
	int	i;
	int	j;

	j = 0;
	size = ft_strlen(map);
	i = size - 4;
	while (map[i] == cmp[j])
	{
		if (map[i] == '\0' && cmp[j] == '\0')
			return (1);
		i++;
		j++;
	}
	return (0);
}

char	*ft_strdup(char *s)
{
	char	*dest;
	int		i;

	dest = ft_calloc(sizeof(char), (ft_strlen(s) + 1));
	i = 0;
	if (dest == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
