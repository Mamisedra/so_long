/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:29:26 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/29 17:23:11 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_begin(t_data *data, char **map, void *show)
{
	int	heigth;
	int	width;
	int	i;

	heigth = 0;
	i = 0;
	while (map[heigth] != NULL)
	{
		width = 0;
		while (map[heigth][width] != '\0' && map[heigth][width] != '\n')
		{
			if (heigth == 0 && width == 0 && map[heigth][width] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall[5], width * 64, heigth * 64);
			else if (heigth == 0 && (width != ft_strlen_list(map[heigth]) - 1) && map[heigth][width] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall[0], width * 64, heigth * 64);
			else if (heigth == 0 && (width == ft_strlen_list(map[heigth]) - 1) && map[heigth][width] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall[4], width * 64, heigth * 64);
			else if ((heigth == ft_countline_map(map) - 1 ) && map[heigth][width] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall[2], width * 64, heigth * 64);
			else if (width == 0 && map[heigth][width] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall[3], width * 64, heigth * 64);
			else if ((width == ft_strlen_list(map[heigth]) - 1) && map[heigth][width] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall[1], width * 64, heigth * 64);
			else if (map[heigth][width] == '1')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->stop[i], width * 64, heigth * 64);
				i++;
				if (i == 4)
					i = 0;
			}
			else if (map[heigth][width] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, show, width * 64, heigth * 64);
			else if (map[heigth][width] == 'E' || map[heigth][width] == 'S')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->start, width * 64, heigth * 64);
			else if (map[heigth][width] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->skills, width * 64, heigth * 64);
			else
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->none , width * 64, heigth * 64);
			width ++;
		}
		heigth ++;
	}
}

int	ft_countline_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

void	input_wall(t_data *data)
{
	data->wall[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/wall_up.xpm", &data->img_width, &data->img_height);
	data->wall[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/wall_rigth.xpm", &data->img_width, &data->img_height);
	data->wall[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/wall_down.xpm", &data->img_width, &data->img_height);
	data->wall[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/wall_left.xpm", &data->img_width, &data->img_height);
	data->wall[4] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/wall_up_rigth.xpm", &data->img_width, &data->img_height);
	data->wall[5] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/wall_up_left.xpm", &data->img_width, &data->img_height);
}

void	input_stop(t_data *data)
{
	data->stop[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/stop_0.xpm", &data->img_width, &data->img_height);
	data->stop[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/stop_3.xpm", &data->img_width, &data->img_height);
	data->stop[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/stop_2.xpm", &data->img_width, &data->img_height);
	data->stop[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/stop_1.xpm", &data->img_width, &data->img_height);
}

void	show_anim(void **image, t_data *data, int x, int y)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, image[i], x * 64, y * 64);
		mlx_do_sync(data->mlx_ptr);
		usleep(500000);
		i++;
	}
}
