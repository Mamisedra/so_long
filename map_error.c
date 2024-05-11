/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 22:58:47 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/11 16:12:36 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_error.h"

int	check_argument(char arg)
{
	if (arg != '1' && arg != '0' && arg != 'P' && arg != 'C' && arg != 'E')
		return (0);
	return (1);
}

int	check_P_or_E(char *map[], char check)
{
	int l;
	int c;
	int cpt;
	char arg;

	l = 0;
	cpt = 0;
	while (map[l])
	{
		c = 0;
		while (map[l][c])
		{
			arg = map[l][c];
			if (arg == check)
				cpt++;
			if (cpt > 1)
				return (0);
			c++;
		}
		l++;
	}
	if (cpt == 0)
		return (0);
	return (1);
}

int check_C(char *map[])
{
	int l;
	int c;
	int cpt;
	char arg;

	l = 0;
	cpt = 0;
	while (map[l])
	{
		c = 0;
		while (map[l][c])
		{
			arg = map[l][c];
			if (arg == 'C')
				cpt++;
			if (cpt > 0)
				return (1);
			c++;
		}
		l++;
	}
	return (0);
}

int	check_tence(char *map[])
{
	int i;
	int max;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[i])
	{
		max = ft_strlen(map[i]);
		if (map[i][0] != '1' || map[i][max] != '1')
			return (0);
	}
	return (1);
}