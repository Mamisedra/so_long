/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:31:19 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/11 11:01:21 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen_g(char	*str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_strchr_g(char *store, char c)
{
	int	i;

	if (!store)
		return (-1);
	i = 0;
	while (store[i] != '\0')
	{
		if (store[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin_g(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*join;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	join = malloc ((ft_strlen_g(s1) + ft_strlen_g(s2) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		join[i++] = s2[j++];
	join[i] = '\0';
	return (free(s1), join);
}

char	*ft_strdup_g(char *buffer)
{
	char	*dup;
	int		size;
	int		i;

	size = ft_strlen_g(buffer);
	if (size == 0)
		return (NULL);
	dup = malloc(sizeof(char) * (size + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (buffer[i] != '\0')
	{
		dup[i] = buffer[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	ft_strcpy_g(char *store, char *reste)
{
	int	i;

	i = 0;
	while (store[i] && store[i] != '\n')
	{
		reste[i] = store[i];
		i++;
	}
	if (store[i] == '\n')
	{
		reste[i] = store[i];
		i++;
	}
	reste[i] = '\0';
}
