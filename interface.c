/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:49:38 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/13 15:45:14 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"
#include "minilibx-linux/mlx.h"

int	handle_no_event(void *data)
{
	/* fonction sans evenement*/
	return (0);
}

int	program_quit(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_loop_end(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_escap(int key, t_data *data)
{
	if (key == ESC)
		program_quit(data);
	return (0);
}

int handle_key(int keysym, t_data *data)
{
	
	if (keysym == UP)
		ft_printf("HAUT\n");
	else if (keysym == DOWN)
		ft_printf("BAS\n");
	else if (keysym == LEFT)
		ft_printf("GAUCHE\n");
	else if (keysym == RIGHT)
		ft_printf("DROIT\n");
	else ft_printf("Vous etes hors touche %d\n", keysym);
	return (0);
}
