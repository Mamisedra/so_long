/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monstre_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:47:35 by mranaivo          #+#    #+#             */
/*   Updated: 2024/06/21 13:29:57 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_enemy(t_data *data)
{
	int	pos_x;

	pos_x = 0;
	if (data->map[data->e_y][data->e_x - 1] == '0')
	{
		data->map[data->e_y][data->e_x - 1] = 'K';
		pos_x = data->e_x - 1;
	}
	if (pos_x != 0)
	{
		data->enemy_pos_y[0] = data->e_y;
		data->enemy_pos_x[0] = pos_x;
	}
	place_define(data);
	place_enemy_2(data);
}

void	place_enemy_2(t_data *data)
{
	int	pos_y;

	pos_y = 0;
	if (data->map[data->e_y - 1][data->e_x] == '0')
	{
		data->map[data->e_y - 1][data->e_x] = 'K';
		pos_y = data->e_y - 1;
	}
	else if (data->map[data->e_y + 1][data->e_x] == '0')
	{
		data->map[data->e_y + 1][data->e_x] = 'K';
		pos_y = data->e_y + 1;
	}
	if (pos_y != 0)
	{
		data->enemy_pos_y[1] = pos_y;
		data->enemy_pos_x[1] = data->e_x;
	}
}

void	place_enemy_final(char **map, int heigth, int width)
{
	if (heigth > 5 && width > 5)
	{
		map[1][1] = 'K';
		map[heigth - 2][1] = 'K';
		map[1][width - 2] = 'K';
		map[heigth - 2][width - 2] = 'K';
	}
}

void	place_define(t_data *data)
{
	int	heigth;
	int	width;

	heigth = ft_countline_map(data->map);
	width = ft_strlen_list(data->map[0]);
	data->enemy_pos_y[2] = 1;
	data->enemy_pos_x[2] = 1;
	data->enemy_pos_x[3] = 1;
	data->enemy_pos_y[3] = heigth - 2;
	data->enemy_pos_x[4] = width - 2;
	data->enemy_pos_y[4] = 1;
	data->enemy_pos_x[5] = width - 2;
	data->enemy_pos_y[5] = heigth - 2;
}

int	gameover(t_data *data)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (data->enemy_pos_y[i] == data->y && data->enemy_pos_x[i] == data->x)
		{
			i = 1;
			break ;
		}
		i++;
	}
	if (i == 1)
	{
		ft_printf("GAME OVER, YOU LOSE\n");
		program_quit(data);
	}
	return (0);
}
