/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map_print_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:49:06 by mranaivo          #+#    #+#             */
/*   Updated: 2024/06/05 14:24:28 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_add_map_print(t_data *data, char **map, int heigth, int width)
{
	static int	i = 0;
	static int aff = 0;
	if (aff % 4 == 0 && aff != 0)
		i = 0;
	if (map[heigth][width] == '1')
	{
		mlx_put_image_to_window(data->mlx_ptr, \
		data->win_ptr, data->stop[i], width * 64, heigth * 64);
		i++;
		if (i == 4)
			i = 0;
		aff ++;
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
}
