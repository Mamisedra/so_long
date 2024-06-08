/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:11:14 by mranaivo          #+#    #+#             */
/*   Updated: 2024/06/08 17:10:35 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		exit(EXIT_FAILURE);
	data->map = ft_list_to_tab(argc, argv);
	give_all_pos(data);
	check_all_access(data);
	ft_startinit(data);
	place_enemy(data);
	input_image(data);
	mlx_key_hook(data->win_ptr, answer_key, data);
	mlx_hook(data->win_ptr,17,1L<<17, program_quit, data);
	mlx_loop_hook(data->win_ptr, gameover, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}