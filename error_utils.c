/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:29:56 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/19 17:17:12 by mranaivo         ###   ########.fr       */
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
	int len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			len--;
			i++;
		}
		if (str[i] != '0' || str[i] != 'C' || str[i] != 'E' || str[i] != '1' || str[i] != 'P')
			return (-1);
		i++;
		len ++;
	}
	return (len);
}
void	ft_freemap(int i, char **map)
{
	while (i > 0)
		free(map[--i]);
	free(map);
}