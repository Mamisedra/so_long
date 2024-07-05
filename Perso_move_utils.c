/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Perso_move_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:37:58 by mranaivo          #+#    #+#             */
/*   Updated: 2024/06/21 13:23:19 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "interface.h"

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
		ft_printofkey(data, key);
	}
}
