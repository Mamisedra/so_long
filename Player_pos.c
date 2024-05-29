/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 23:57:43 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/23 01:04:41 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_change_final(t_data *data, int cd)
{
	if (cd == -1)
		data->map[data->e_y][data->e_x] = 'S';
	else if (cd == 1)
		data->map[data->e_y][data->e_x] = 'E';
}

void	give_all_pos(t_data *data)
{
	ft_where_p(data);
	ft_where_e(data);
	ft_change_final(data, -1);
}

void	ft_where_p(t_data *data)
{
	int	i;
	int	j;
	int	cd;

	i = 0;
	cd = 0;
	while (data->map[i++] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0')
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

void	ft_where_e(t_data *data)
{
	int	i;
	int	j;
	int	cd;

	i = 0;
	cd = 0;
	while (data->map[i++] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0')
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
			data->e_x = j;
			data->e_y = i;
			break ;
		}
	}
}
