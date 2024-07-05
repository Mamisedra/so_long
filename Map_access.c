/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map_access.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:10:10 by mranaivo          #+#    #+#             */
/*   Updated: 2024/06/21 13:21:44 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "interface.h"
#include "so_long.h"

static void	ft_free_visite(int **visite, int heigth)
{
	int	i;

	i = 0;
	while (i < heigth)
	{
		free(visite[i]);
		i++;
	}
	free(visite);
}

void	police_of_game(char **map, int x, int y, int **visite)
{
	int	heigth;
	int	width;

	heigth = ft_countline_map(map);
	width = ft_strlen_list(map[0]);
	if (x < 0 || x >= heigth || y < 0 || y >= width \
	|| visite[x][y] || map[x][y] == '1')
		return ;
	visite[x][y] = 1;
	police_of_game(map, x + 1, y, visite);
	police_of_game(map, x - 1, y, visite);
	police_of_game(map, x, y + 1, visite);
	police_of_game(map, x, y - 1, visite);
}

int	**get_visit(int heigth, int width)
{
	int	**visite;
	int	i;

	visite = (int **)malloc((heigth + 1) * sizeof(int *));
	if (!visite)
		return (NULL);
	i = 0;
	while (i < heigth)
	{
		visite[i] = ft_calloc(width + 1, sizeof(int));
		if (!visite[i])
		{
			ft_free_visite(visite, i);
			return (NULL);
		}
		i++;
	}
	return (visite);
}

int	access_chr(char **map, int heigth, int width, int **visite)
{
	int	i;
	int	j;
	int	access;

	i = 0;
	access = 1;
	while (i < heigth && access)
	{
		j = 0;
		while (j < width && access)
		{
			if ((map[i][j] == 'C' || map[i][j] == 'E') && visite[i][j] == 0)
				access = 0;
			j++;
		}
		i++;
	}
	return (access);
}

void	check_all_access(t_data *data)
{
	int	heigth;
	int	width;
	int	**visite;

	heigth = ft_countline_map(data->map);
	width = ft_strlen_list(data->map[0]);
	visite = get_visit(heigth, width);
	if (!visite)
	{
		ft_printf("Error: test access bloquer\n");
		return ;
	}
	police_of_game(data->map, data->y, data->x, visite);
	if (!access_chr(data->map, heigth, width, visite))
	{
		ft_printf("ERROR: E ou C inaccessible\n");
		ft_free_visite(visite, heigth);
		ft_free_all(data->map);
		free(data);
		exit(EXIT_FAILURE);
	}
	ft_free_visite(visite, heigth);
}
