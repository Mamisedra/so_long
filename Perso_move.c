/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Perso_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:47:07 by mranaivo          #+#    #+#             */
/*   Updated: 2024/06/20 15:34:21 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "interface.h"

int	answer_key(int keysym, t_data *data)
{
	static int	i = 0;

	if (keysym == ESC)
		program_quit(data);
	ft_void(data, keysym);
	if (keysym == UP)
		i += move_up(data, keysym);
	else if (keysym == DOWN)
		i += move_down(data, keysym);
	else if (keysym == LEFT)
		i += move_left(data, keysym);
	else if (keysym == RIGHT)
		i += move_rigth(data, keysym);
	ft_void(data, keysym);
	ft_printf("Move : %d\nCollect : %d\n", i, data->collect);
	return (0);
}

int	move_rigth(t_data *data, int key)
{
	int	x;
	int	y;

	x = data->x;
	y = data->y;
	if (key == RIGHT)
	{
		if (data->map[y][x + 1] == 'C')
		{
			show_anim(data->player_rigth, data, x, y);
			position_swap(data, x, y, 'R');
			ft_print_begin(data, data->map, data->player_attaque[0]);
			show_anim(data->player_attaque, data, x + 1, y);
			return (data->collect --, 1);
		}
		if ((data->map[y][x + 1] == '0' || data->map[y][x + 1] == 'C')
			|| (data->map[y][x + 1] == 'S' || data->map[y][x + 1] == 'E'))
		{
			show_anim(data->player_rigth, data, x, y);
			position_swap(data, x, y, 'R');
		}
		else
			return (0);
	}
	return (ft_print_begin(data, data->map, data->player_rigth[0]), 1);
}

int	move_left(t_data *data, int key)
{
	int	x;
	int	y;

	x = data->x;
	y = data->y;
	if (key == LEFT)
	{
		if (data->map[y][x - 1] == 'C')
		{
			show_anim(data->player_left, data, x, y);
			position_swap(data, x, y, 'L');
			ft_print_begin(data, data->map, data->player_attaque[0]);
			show_anim(data->player_attaque, data, x - 1, y);
			return (data->collect --, 1);
		}
		if ((data->map[y][x - 1] == '0' || data->map[y][x - 1] == 'C')
			|| (data->map[y][x - 1] == 'S' || data->map[y][x - 1] == 'E'))
		{
			show_anim(data->player_left, data, x, y);
			position_swap(data, x, y, 'L');
		}
		else
			return (0);
	}
	return (ft_print_begin(data, data->map, data->player_left[0]), 1);
}

int	move_up(t_data *data, int key)
{
	int	x;
	int	y;

	x = data->x;
	y = data->y;
	if (key == UP)
	{
		if (data->map[y - 1][x] == 'C')
		{
			show_anim(data->player_up, data, x, y);
			position_swap(data, x, y, 'U');
			ft_print_begin(data, data->map, data->player_attaque[0]);
			show_anim(data->player_attaque, data, x, y - 1);
			return (data->collect --, 1);
		}
		if ((data->map[y - 1][x] == 'C' || data->map[y - 1][x] == '0')
			|| (data->map[y - 1][x] == 'S' || data->map[y - 1][x] == 'E'))
		{
			show_anim(data->player_up, data, x, y);
			position_swap(data, x, y, 'U');
		}
		else
			return (0);
	}
	return (ft_print_begin(data, data->map, data->player_up[0]), 1);
}

int	move_down(t_data *data, int key)
{
	int	x;
	int	y;

	x = data->x;
	y = data->y;
	if (key == DOWN)
	{
		if (data->map[y + 1][x] == 'C')
		{
			show_anim(data->player_down, data, x, y);
			position_swap(data, x, y, 'D');
			ft_print_begin(data, data->map, data->player_attaque[0]);
			show_anim(data->player_attaque, data, x, y + 1);
			return (data->collect --, 1);
		}
		if ((data->map[y + 1][x] == '0' || data->map[y + 1][x] == 'C')
			|| (data->map[y + 1][x] == 'S' || data->map[y + 1][x] == 'E'))
		{
			show_anim(data->player_down, data, x, y);
			position_swap(data, x, y, 'D');
		}
		else
			return (0);
	}
	return (ft_print_begin(data, data->map, data->player_down[0]), 1);
}
