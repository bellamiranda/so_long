/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:15:06 by ismirand          #+#    #+#             */
/*   Updated: 2024/04/18 16:08:21 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	write_movements(t_game *game)
{
	write(1, "Movements: ", 11);
	ft_putnbr_fd(game->movements, 1);
	write(1, "\n", 1);
	write_movements_on_window(game);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else if (n < 10)
	{
		c = n + '0';
		write(fd, &c, 1);
	}
}

char	**ft_mtxdup(t_game *game)
{
	char	**dest;
	int		i;

	i = -1;
	dest = ft_calloc(sizeof(char *), game->height + 1);
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
