/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:41:07 by mranaivo          #+#    #+#             */
/*   Updated: 2024/06/20 14:41:44 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:29:26 by mranaivo          #+#    #+#             */
/*   Updated: 2024/06/20 14:40:45 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			image[i], x * 64, y * 64);
		mlx_do_sync(data->mlx_ptr);
		usleep(1000);
		i++;
	}
	mlx_do_sync(data->mlx_ptr);
}
