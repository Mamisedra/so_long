/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:32:21 by mranaivo          #+#    #+#             */
/*   Updated: 2024/06/01 16:46:29 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "so_long.h"

void	ft_startinit(t_data *data)
{
	size_t	width;
	size_t	heigth;

	width = (size_t)ft_strlen_list(data->map[0]) * 64;
	heigth = 0;
	while (data->map[heigth] != NULL)
		heigth++;
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		exit(EXIT_FAILURE);
	data->win_ptr = mlx_new_window(data->mlx_ptr, width,
			(heigth * 64), "so_long");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free(data);
		exit(EXIT_FAILURE);
	}
}

void	ft_map_print(t_data *data, char **map, int heigth, int width)
{
	static int	i = 0;

	if (heigth == 0 && width == 0 && map[heigth][width] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,data->wall[5], width * 64, heigth * 64);
	else if (heigth == 0 && (width != ft_strlen_list(map[heigth]) - 1) && map[heigth][width] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall[0], width * 64, heigth * 64);
	else if (heigth == 0 && (width == ft_strlen_list(map[heigth]) - 1) && map[heigth][width] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall[4], width * 64, heigth * 64);
	else if ((heigth == ft_countline_map(map) - 1) && map[heigth][width] == '1')
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
	else if (map[heigth][width] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->skills, width * 64, heigth * 64);
}

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
			ft_map_print(data, map, heigth, width);
			if (map[heigth][width] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, show, width * 64, heigth * 64);
			else if (map[heigth][width] == 'E' || map[heigth][width] == 'S')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->start, width * 64, heigth * 64);
			else if (map[heigth][width] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->none, width * 64, heigth * 64);
			width ++;
		}
		heigth ++;
	}
}

void	position_swap(t_data *data, int x, int y, char c)
{
	int	dx;
	int	dy;

	dy = 0;
	dx = 0;
	if (c == 'L')
		dx = -1;
	else if (c == 'D')
		dy = 1;
	else if (c == 'U')
		dy = -1;
	else if (c == 'R')
		dx = 1;
	data->map[y + dy][x + dx] = 'P';
	data->map[y][x] = '0';
	data->x = x + dx;
	data->y = y + dy;
}
