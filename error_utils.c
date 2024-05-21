/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:29:56 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/21 13:29:56 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_countchar(char *str, char c)
{
	int	i;
	int	cpt;

	i = 0;
	cpt = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			cpt++;
		i++;
	}
	return (cpt);
}

int	ft_check_intru(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '0' && str[i] != 'C' && str[i] != 'E' && str[i] != '1' && str[i] != 'P')
			break ;
		i++;
	}
	if (i == ft_strlen_list(str) && ( str[i] == '\0' || str[i] == '\n'))
		return (1);
	else
	 	return (0);
	return (1);
}

int	ft_strlen_list(char	*str)
{
	int	i;

	i = 0;
	while(str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

void	ft_freemap(int i, char **map)
{
	while (i > 0)
		free(map[--i]);
	free(map);
}

void	ft_free_all(char **map)
{
	int i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}