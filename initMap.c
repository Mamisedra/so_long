/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 23:06:16 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/18 03:13:11 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"
#include "minilibx-linux/mlx.h"

int	input_image(t_data *data)
{
	void	*stop;
	void	*skills;
	void	*player_D;
	void	*player_G;
	void	*none;
	void	*finish;
	int		img_width;
	int		img_heigth;
	t_move	*move;

	none = mlx_xpm_file_to_image(data->mlx_ptr, "./xpmimg/none.xpm", &img_width, &img_heigth);
	stop = mlx_xpm_file_to_image(data->mlx_ptr, "./xpmimg/stop.xpm", &img_width, &img_heigth);
	skills = mlx_xpm_file_to_image(data->mlx_ptr, "./xpmimg/skills.xpm", &img_width, &img_heigth);
	finish = mlx_xpm_file_to_image(data->mlx_ptr, "./xpmimg/finish.xpm", &img_width, &img_heigth);
	player_D = mlx_xpm_file_to_image(data->mlx_ptr, "./xpmimg/player_D.xpm", &img_width, &img_heigth);
	player_G = mlx_xpm_file_to_image(data->mlx_ptr, "./xpmimg/player_G.xpm", &img_width, &img_heigth);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, none, 128, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, stop, 64, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, player_D, 128, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, skills, 192, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, finish, 256, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, player_G, 320, 0);
	return (1);
}
void ft_startinit(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		exit(EXIT_FAILURE);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGTH, "so_long");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		exit(EXIT_FAILURE);
	}
}