/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Perso_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:47:07 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/29 17:27:02 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"
#include "so_long.h"

int	answer_key(int keysym, t_data *data)
{
	static int	i = 0;

	if (keysym == ESC)
		program_quit(data);
	if (keysym == UP)
		i += move_up(data, keysym);
	else if (keysym == DOWN)
		i += move_down(data, keysym);
	else if (keysym == LEFT)
		i += move_left(data, keysym);
	else if (keysym == RIGHT)
		i += move_rigth(data, keysym);
	if (data->map[data->y][data->x] != '1')
		ft_printf("Nbre de pas : %d\n", i);
	ft_printf("Collecte : %d\n", data->collect);
	if (data->collect == 0)
	{
		ft_change_final(data, 1);
		ft_printmap_rigth(data, data->map);
		you_win(data, keysym);
	}
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

		if ((data->map[y][x + 1] == '0' || data->map[y][x + 1] == 'C')
			|| (data->map[y][x + 1] == 'S'))
		{
			if (data->map[y][x + 1] == 'C')
				data->collect --;
			data->map[y][x + 1] = 'P';
			data->map[y][x] = '0';
			data->x = x + 1;
			data->y = y;
		}
	}
	ft_printmap_rigth(data, data->map);
	return (1);
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
			data->map[y][x - 1] = 'P';
			data->map[y][x] = '0';
			data->x = x - 1;
			data->y = y;
			ft_print_begin(data, data->map, data->player_attaque[0]);
			show_anim(data->player_attaque, data, x - 1, y);
			data->collect --;
			return (1);
		}
		else if ((data->map[y][x - 1] == '0' || data->map[y][x - 1] == 'C')
			|| (data->map[y][x - 1] == 'S'))
		{
			show_anim(data->player_left, data, x, y);
			data->map[y][x - 1] = 'P';
			data->map[y][x] = '0';
			data->x = x - 1;
			data->y = y;
		}
	}
	ft_print_begin(data, data->map, data->player_left[0]);
	return (1);
}

int	move_up(t_data *data, int key)
{
	int	x;
	int	y;

	x = data->x;
	y = data->y;
	if (key == UP)
	{
		if ((data->map[y - 1][x] == '0' || data->map[y - 1][x] == 'C')
			|| (data->map[y - 1][x] == 'S'))
		{
			if (data->map[y - 1][x] == 'C')
				data->collect --;
			data->map[y - 1][x] = 'P';
			data->map[y][x] = '0';
			data->x = x;
			data->y = y - 1;
		}
	}
	ft_printmap_up(data, data->map);
	return (1);
}

int	move_down(t_data *data, int key)
{
	int	x;
	int	y;

	x = data->x;
	y = data->y;
	if (key == DOWN)
	{
		if ((data->map[y + 1][x] == '0' || data->map[y + 1][x] == 'C')
			|| (data->map[y + 1][x] == 'S'))
		{
			if (data->map[y + 1][x] == 'C')
				data->collect --;
			data->map[y + 1][x] = 'P';
			data->map[y][x] = '0';
			data->x = x;
			data->y = y + 1;
		}
	}
	ft_printmap_down(data, data->map);
	return (1);
}
