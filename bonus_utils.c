/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:02:11 by mranaivo          #+#    #+#             */
/*   Updated: 2024/06/08 16:17:11 by mranaivo         ###   ########.fr       */
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
	static int i = 0;

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
			place_enemy_final(data->map, ft_countline_map(data->map), ft_strlen_list(data->map[0]));
			i = 1;
		}
		ft_printofkey(data, key);
	}
}