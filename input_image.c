/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:34:40 by mranaivo          #+#    #+#             */
/*   Updated: 2024/06/08 14:42:47 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "so_long.h"

void	input_image(t_data *data)
{
	data->collect = ft_count_collect(data);
	data->none = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/none.xpm", &data->img_width, &data->img_height);
	data->skills = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/skills.xpm", &data->img_width, &data->img_height);
	data->finish = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/finish.xpm", &data->img_width, &data->img_height);
	data->start = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/start.xpm", &data->img_width, &data->img_height);
	data->player = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/player.xpm", &data->img_width, &data->img_height);
	input_go_down(data);
	input_go_left(data);
	input_go_rigth(data);
	input_go_up(data);
	input_stop(data);
	input_wall(data);
	ft_print_begin(data, data->map, data->player);
}

void	input_go_up(t_data *data)
{
	data->player_up[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/up_0.xpm", &data->img_width, &data->img_height);
	data->player_up[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/up_1.xpm", &data->img_width, &data->img_height);
	data->player_up[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/up_2.xpm", &data->img_width, &data->img_height);
	data->player_up[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/up_3.xpm", &data->img_width, &data->img_height);
	data->player_attaque[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/attaque_0.xpm", &data->img_width, &data->img_height);
	data->player_attaque[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/attaque_1.xpm", &data->img_width, &data->img_height);
	data->player_attaque[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/attaque_2.xpm", &data->img_width, &data->img_height);
	data->player_attaque[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/attaque_3.xpm", &data->img_width, &data->img_height);
}

void	input_go_down(t_data *data)
{
	data->player_down[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/down_0.xpm", &data->img_width, &data->img_height);
	data->player_down[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/down_1.xpm", &data->img_width, &data->img_height);
	data->player_down[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/down_2.xpm", &data->img_width, &data->img_height);
	data->player_down[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/down_3.xpm", &data->img_width, &data->img_height);
	data->enemy_left = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/enemy_left.xpm", &data->img_width, &data->img_height);
	data->enemy_right = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/enemy_rigth.xpm", &data->img_width, &data->img_height);
}

void	input_go_rigth(t_data *data)
{
	data->player_rigth[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/rigth_0.xpm", &data->img_width, &data->img_height);
	data->player_rigth[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/rigth_1.xpm", &data->img_width, &data->img_height);
	data->player_rigth[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/rigth_2.xpm", &data->img_width, &data->img_height);
	data->player_rigth[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/rigth_3.xpm", &data->img_width, &data->img_height);
}

void	input_go_left(t_data *data)
{
	data->player_left[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/left_0.xpm", &data->img_width, &data->img_height);
	data->player_left[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/left_1.xpm", &data->img_width, &data->img_height);
	data->player_left[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/left_2.xpm", &data->img_width, &data->img_height);
	data->player_left[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./xpmimg/left_3.xpm", &data->img_width, &data->img_height);
}
