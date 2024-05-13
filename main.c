/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:26:08 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/13 15:46:12 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

int	main(void)
{
	t_data	*data;

	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		exit(EXIT_FAILURE);
	data->win_ptr = mlx_new_window(data->mlx_ptr, 700, 450, "so_long");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		exit(EXIT_FAILURE);
	}
	mlx_key_hook(data->win_ptr, ft_escap, data);
	mlx_hook(data->win_ptr,17,1L<<17, program_quit, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}