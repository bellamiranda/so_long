/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:34:22 by ismirand          #+#    #+#             */
/*   Updated: 2024/03/03 20:23:09 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*dest;
	size_t	i;

	dest = malloc(nmemb * size);
	i = 0;
	if (dest == NULL)
		return (NULL);
	while (i < (nmemb * size))
		dest[i++] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_clean(char **s1, char **s2)
{
	free(*s1);
	free(*s2);
	*s1 = NULL;
	return (NULL);
}
