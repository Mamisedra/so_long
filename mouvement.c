/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:02:22 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/21 15:39:57 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_where_P(t_data *data)
{
	int i;
	int j;
	int	cd;

	i = 0;
	cd = 0;
	while (data->map[i++] != NULL)
	{
		j = 0;
		while(data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'P')
			{
				cd = 1;
				break ;
			}
			j++;
		}
		if (cd)
		{
			data->x = j;
			data->y = i;
			break ;
		}
	}
}

void	ft_where_E(t_data *data)
{
	int i;
	int j;
	int	cd;

	i = 0;
	cd = 0;
	while (data->map[i++] != NULL)
	{
		j = 0;
		while(data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'E')
			{
				cd = 1;
				break ;
			}
			j++;
		}
		if (cd)
		{
			data->E_x = j;
			data->E_y = i;
			break ;
		}
	}
}

int	move_bas_gauche(int key, t_data *data)
{
	int	x;
	int	y;
	int i;

	x = data->x;
	y = data->y;
	i = 0;
	if(key == LEFT)
	{
		if(data->map[y][x - 1] == '0' || data->map[y][x - 1] == 'C')
		{
			if (data->map[y][x - 1] == 'C')
				data->collect --;
			data->map[y][x - 1] = 'P';
			data->map[y][x] = '0';
			data->x = x - 1;
			data->y = y;
			i = 1;
		}
	}
	if(key == DOWN)
	{
		if(data->map[y + 1][x] == '0' || data->map[y + 1][x] == 'C')
		{
			if (data->map[y + 1][x] == 'C')
				data->collect --;
			data->map[y + 1][x] = 'P';
			data->map[y][x] = '0';
			data->x = x;
			data->y = y + 1;
			i = 1;
		}
	}
	ft_printmap_left(data, data->map);
	return (i);
}

int	move_haut_droite(int key, t_data *data)
{
	int	x;
	int	y;
	int i;

	x = data->x;
	y = data->y;
	i = 0;
	if(key == RIGHT)
	{
		if(data->map[y][x + 1] == '0' || data->map[y][x + 1] == 'C')
		{
			if (data->map[y][x + 1] == 'C')
				data->collect --;
			data->map[y][x + 1] = 'P';
			data->map[y][x] = '0';
			data->x = x + 1;
			data->y = y;
			i = 1;
		}
	}
	if(key == UP)
	{
		if(data->map[y - 1][x] == '0' || data->map[y - 1][x] == 'C')
		{
			if (data->map[y - 1][x] == 'C')
				data->collect --;
			data->map[y - 1][x] = 'P';
			data->map[y][x] = '0';
			data->x = x;
			data->y = y - 1;
			i = 1;
		}
	}
	ft_printmap_rigth(data, data->map);
	return (i);
}

void	ft_change_final(t_data *data, int cd)
{
	if (cd == -1)
		data->map[data->E_y][data->E_x] = 'S';
	else if (cd == 1)
		data->map[data->E_y][data->E_x] = 'E';
}
