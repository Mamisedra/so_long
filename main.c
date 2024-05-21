/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:26:08 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/21 13:46:57 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"
#include "so_long.h"

int	main(int argc, char *argv[])
 {
 	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		exit(EXIT_FAILURE);
	data->map = ft_list_to_tab(argc, argv);
 	ft_where_P(data);
	ft_printf("P(x = %d, y = %d)", data->x, data->y);
	ft_startinit(data);
 	input_image(data);
	mlx_key_hook(data->win_ptr, answer_key,data);
 	mlx_hook(data->win_ptr,17,1L<<17, program_quit, data);
 	mlx_loop(data->mlx_ptr);
	return (0);
 }