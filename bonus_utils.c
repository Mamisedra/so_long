/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:02:11 by mranaivo          #+#    #+#             */
/*   Updated: 2024/06/20 15:59:22 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_printofkey(t_data *data, int key)
{
	if (key == UP)
		ft_print_begin(data, data->map, data->player_up[0]);
	else if (key == DOWN)
		ft_print_begin(data, data->map, data->player_down[0]);
	else if (key == LEFT)
		ft_print_begin(data, data->map, data->player_left[0]);
	else if (key == RIGHT)
		ft_print_begin(data, data->map, data->player_rigth[0]);
}

void	ft_void(t_data *data, int key)
{
	static int	i = 0;

	if ((data->e_x == data->x && data->e_y == data->y) && data->collect == 0)
	{
		ft_printf("You win CONGRATS\n");
		program_quit(data);
	}
	else if (data->collect != 0 && data->map[data->e_y][data->e_x] == '0')
	{
		data->map[data->e_y][data->e_x] = 'S';
		ft_printofkey(data, key);
	}
	if (data->collect == 0)
	{
		data->map[data->e_y][data->e_x] = 'E';
		if (i == 0)
		{
			place_enemy_final(data->map, \
			ft_countline_map(data->map), ft_strlen_list(data->map[0]));
			i = 1;
		}
		ft_printofkey(data, key);
	}
}

void	move_back(t_data *data, int *pos_x, int *pos_y, char c)
{
	gameover(data);
	if (c == 'D')
	{
		data->map[*pos_y - 1][*pos_x] = 'K';
		data->map[*pos_y][*pos_x] = '0';
		(*pos_y)--;
	}
	if (c == 'U')
	{
		data->map[*pos_y + 1][*pos_x] = 'K';
		data->map[*pos_y][*pos_x] = '0';
		(*pos_y)++;
	}
	if (c == 'L')
	{
		data->map[*pos_y][*pos_x + 1] = 'K';
		data->map[*pos_y][*pos_x] = '0';
		(*pos_x)++;
	}
	if (c == 'R')
	{
		data->map[*pos_y][*pos_x - 1] = 'K';
		data->map[*pos_y][*pos_x] = '0';
		(*pos_x)--;
	}
}

void	move_go(t_data *data, int *pos_x, int *pos_y, char c)
{
	gameover(data);
	if (c == 'U')
	{
		data->map[*pos_y - 1][*pos_x] = 'K';
		data->map[*pos_y][*pos_x] = '0';
		(*pos_y)--;
	}
	if (c == 'D')
	{
		data->map[*pos_y + 1][*pos_x] = 'K';
		data->map[*pos_y][*pos_x] = '0';
		(*pos_y)++;
	}
	if (c == 'R')
	{
		data->map[*pos_y][*pos_x + 1] = 'K';
		data->map[*pos_y][*pos_x] = '0';
		(*pos_x)++;
	}
	if (c == 'L')
	{
		data->map[*pos_y][*pos_x - 1] = 'K';
		data->map[*pos_y][*pos_x] = '0';
		(*pos_x)--;
	}
}
