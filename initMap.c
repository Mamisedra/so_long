/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 23:06:16 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/21 13:46:55 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"
#include "minilibx-linux/mlx.h"
#include "so_long.h"

void ft_startinit(t_data *data)
{
	size_t	width;
	size_t heigth;

	width = (size_t)ft_strlen_list(data->map[0]) * 64;
	heigth = 0;
	while (data->map[heigth] != NULL)
		heigth++;
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		exit(EXIT_FAILURE);
	data->win_ptr = mlx_new_window(data->mlx_ptr, width, (heigth * 64), "so_long");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		exit(EXIT_FAILURE);
	}
}

void	input_image(t_data *data)
{
	data->none = mlx_xpm_file_to_image(data->mlx_ptr, "./xpmimg/none.xpm", &data->img_width, &data->img_height);
	data->stop = mlx_xpm_file_to_image(data->mlx_ptr, "./xpmimg/stop.xpm", &data->img_width, &data->img_height);
	data->skills = mlx_xpm_file_to_image(data->mlx_ptr, "./xpmimg/skills.xpm", &data->img_width, &data->img_height);
	data->finish = mlx_xpm_file_to_image(data->mlx_ptr, "./xpmimg/finish.xpm", &data->img_width, &data->img_height);
	data->player_D = mlx_xpm_file_to_image(data->mlx_ptr, "./xpmimg/player_D.xpm", &data->img_width, &data->img_height);
	data->player_G = mlx_xpm_file_to_image(data->mlx_ptr, "./xpmimg/player_G.xpm", &data->img_width, &data->img_height);
	ft_printmap_left(data, data->map);
}

void	ft_printmap_rigth(t_data *data, char **map)
{
	int	heigth;
	int width;

	heigth = 0;
	while(map[heigth] != NULL)
	{
		width = 0;
		while (map[heigth][width] != '\0' && map[heigth][width] != '\n')
		{
			if (map[heigth][width] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->stop, width * 64, heigth * 64);
			else if(map[heigth][width] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->finish, width * 64, heigth * 64);
			else if(map[heigth][width] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player_D, width * 64, heigth * 64);
			else if(map[heigth][width] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->skills, width * 64, heigth * 64);
			else
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->none, width * 64, heigth * 64);
			width++;
		}
		heigth++;
	}
}

void	ft_printmap_left(t_data *data, char **map)
{
	int	heigth;
	int width;

	heigth = 0;
	while(map[heigth] != NULL)
	{
		width = 0;
		while (map[heigth][width] != '\0' && map[heigth][width] != '\n')
		{
			if (map[heigth][width] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->stop, width * 64, heigth * 64);
			else if(map[heigth][width] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->finish, width * 64, heigth * 64);
			else if(map[heigth][width] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player_G, width * 64, heigth * 64);
			else if(map[heigth][width] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->skills, width * 64, heigth * 64);
			else
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->none, width * 64, heigth * 64);
			width++;
		}
		heigth++;
	}
}