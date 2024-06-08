/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monstre_utlis_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:47:35 by mranaivo          #+#    #+#             */
/*   Updated: 2024/06/08 17:08:06 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_enemy(t_data *data)
{
	int pos_x;

	pos_x = 0;
	if (data->map[data->e_y][data->e_x + 1] == '0')
	{
	    data->map[data->e_y][data->e_x + 1] = 'K';
		pos_x = data->e_x + 1;
	}
	else if (data->map[data->e_y][data->e_x - 1] == '0')
	{
	    data->map[data->e_y][data->e_x - 1] = 'K';
		pos_x = data->e_x - 1;
	}
	if (pos_x != 0)
	{
		data->enemy->p1_y = data->e_y;
		data->enemy->p1_x = pos_x;
	}
	place_define(data);
	place_enemy_2(data);
}

void	place_enemy_2(t_data *data)
{
	int pos_y;

	pos_y = 0;
	if (data->map[data->e_y - 1][data->e_x] == '0')
	{
		data->map[data->e_y - 1][data->e_x] = 'K';
		pos_y  = data->e_y - 1;
	}
	else if (data->map[data->e_y + 1][data->e_x] == '0')
	{
		data->map[data->e_y + 1][data->e_x] = 'K';
		pos_y = data->e_y + 1;
	}
	if (pos_y != 0)
	{
		data->enemy->p2_y = pos_y;
		data->enemy->p2_x = data->e_x;
	}
}

void    place_enemy_final(char **map, int heigth, int width)
{
	map[1][1] = 'K';
	map[heigth - 2][1] = 'K';
	map[1][width - 2] = 'K';
	map[heigth - 2][width - 2] = 'K';
}

void	place_define(t_data *data)
{
	int heigth;
	int width;

	heigth = ft_countline_map(data->map);
	width = ft_strlen_list(data->map[0]);
	data->enemy->p3_y = 1;
	data->enemy->p3_x = 1;
	data->enemy->p4_x = 1;
	data->enemy->p4_y = heigth - 2;
	data->enemy->p5_x = width - 2;
	data->enemy->p5_y = 1;
	data->enemy->p6_x = width - 2;
	data->enemy->p6_y = heigth - 2;
}

int	gameover(t_data *data)
{
	int	i;

	i = 0;
	if ((data->enemy->p1_x == data->e_x) && (data->enemy->p1_y == data->e_y))
		i = 1;
    if ((data->enemy->p2_x == data->e_x) && (data->enemy->p2_y == data->e_y))
		i = 1;
    if ((data->enemy->p3_x == data->e_x) && (data->enemy->p3_y == data->e_y))
		i = 1;
    if ((data->enemy->p4_x == data->e_x) && (data->enemy->p4_y == data->e_y))
		i = 1;
    if ((data->enemy->p5_x == data->e_x) && (data->enemy->p5_y == data->e_y))
		i = 1;
    if ((data->enemy->p6_x == data->e_x) && (data->enemy->p6_y == data->e_y))
		i = 1;
    if (i == 1)
	{
		ft_printf("GAME OVER, YOU LOSE\n");
		program_quit(data);
	}
}