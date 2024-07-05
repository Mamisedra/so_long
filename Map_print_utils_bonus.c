/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map_print_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:13:01 by mranaivo          #+#    #+#             */
/*   Updated: 2024/06/20 15:33:33 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_obs(char **map)
{
	int	heigth;
	int	width;
	int	i;
	int	j;
	int	obs;

	heigth = ft_countline_map(map);
	width = ft_strlen_list(map[0]);
	i = 1;
	obs = 0;
	while (i < (heigth - 1))
	{
		j = 1;
		while (j < (width - 1))
		{
			if (map[i][j] == '1')
				obs++;
			j++;
		}
		i++;
	}
	return (obs);
}

void	ft_add_map_print(t_data *data, char **map, int heigth, int width)
{
	static int	i = 0;
	static int	j = 0;
	int			obs;

	obs = ft_count_obs(map);
	if (j == obs)
	{
		i = 0;
		j = 0;
	}
	if (map[heigth][width] == '1')
	{
		mlx_put_image_to_window(data->mlx_ptr, \
		data->win_ptr, data->stop[i], width * 64, heigth * 64);
		i++;
		if (i == 4)
			i = 0;
		j ++;
	}
	else if (map[heigth][width] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, \
	data->win_ptr, data->skills, width * 64, heigth * 64);
}

void	ft_add_print_begin(t_data *data, void *show, int heigth, int width)
{
	ft_map_print(data, data->map, heigth, width);
	if (data->map[heigth][width] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, \
	data->win_ptr, show, width * 64, heigth * 64);
	else if (data->map[heigth][width] == 'S')
		mlx_put_image_to_window(data->mlx_ptr, \
	data->win_ptr, data->start, width * 64, heigth * 64);
	else if (data->map[heigth][width] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, \
	data->win_ptr, data->finish, width * 64, heigth * 64);
	else if (data->map[heigth][width] == '0')
		mlx_put_image_to_window(data->mlx_ptr, \
	data->win_ptr, data->none, width * 64, heigth * 64);
	else if (data->map[heigth][width] == 'K')
		mlx_put_image_to_window(data->mlx_ptr, \
	data->win_ptr, data->enemy_left, width * 64, heigth * 64);
}
