/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:11:14 by mranaivo          #+#    #+#             */
/*   Updated: 2024/06/21 13:35:58 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_carte_ok(t_data *data)
{
	int	heigth;
	int	width;

	heigth = ft_countline_map(data->map);
	width = ft_strlen_list(data->map[0]);
	if (heigth > 5 && width > 5)
		return (1);
	return (0);
}

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
	if (ft_carte_ok(data))
		place_enemy(data);
	input_image(data);
	data->nb_pas = 0;
	mlx_key_hook(data->win_ptr, answer_key, data);
	mlx_hook(data->win_ptr, 17, 1L << 17, program_quit, data);
	if (ft_carte_ok(data))
		mlx_loop_hook(data->mlx_ptr, move, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
