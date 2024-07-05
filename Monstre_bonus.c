/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monstre_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:48:01 by mranaivo          #+#    #+#             */
/*   Updated: 2024/06/20 15:57:25 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	get_next_move(char **map, int *pos_x, int *pos_y, char last_move)
{
	if (map[*pos_y - 1][*pos_x] == '0' && last_move != 'D')
	{
		(*pos_y)--;
		return ('U');
	}
	else if (map[*pos_y][*pos_x + 1] == '0' && last_move != 'L')
	{
		(*pos_x)++;
		return ('R');
	}
	else if (map[*pos_y + 1][*pos_x] == '0' && last_move != 'U')
	{
		(*pos_y)++;
		return ('D');
	}
	else if (map[*pos_y][*pos_x - 1] == '0' && last_move != 'R')
	{
		(*pos_x)--;
		return ('L');
	}
	return ('\0');
}

char	*ft_getroad(char **map, int pos_x, int pos_y)
{
	char	*road;
	int		i;
	char	last_move;
	char	next_move;

	i = 0;
	last_move = '\0';
	road = malloc(sizeof(char) * (NB_PAS + 1));
	if (!road)
		return (NULL);
	while (i < NB_PAS)
	{
		next_move = get_next_move(map, &pos_x, &pos_y, last_move);
		if (next_move == '\0')
			break ;
		road[i] = next_move;
		last_move = next_move;
		i++;
	}
	road[i] = '\0';
	return (road);
}

void	initialize_roads(t_data *data)
{
	ft_strcpy(data, data->road_0, data->road_1);
}

void	move_forward(t_data *data, int *i)
{
	move_go(data, &data->enemy_pos_x[0], \
	&data->enemy_pos_y[0], data->road_0[*i]);
	move_go(data, &data->enemy_pos_x[1], \
	&data->enemy_pos_y[1], data->road_1[*i]);
	(*i)++;
}

void	move_backward(t_data *data, int *i)
{
	(*i)--;
	move_back(data, &data->enemy_pos_x[0], \
	&data->enemy_pos_y[0], data->road_0[*i]);
	move_back(data, &data->enemy_pos_x[1], \
	&data->enemy_pos_y[1], data->road_1[*i]);
}
