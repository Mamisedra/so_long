/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:49:38 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/21 14:00:22 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"
#include "so_long.h"

int	program_quit(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_loop_end(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	ft_free_all(data->map);
	free(data);
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_escap(int key, t_data *data)
{
	if (key == ESC)
		program_quit(data);
	return (0);
}

int answer_key(int keysym, t_data *data)
{
	if (keysym == ESC)
		program_quit(data);
	if (keysym == UP)
	{
		ft_printf("HAUT\n");
		move_haut_droite(keysym, data);
	}
	else if (keysym == DOWN)
	{
		ft_printf("BAS\n");
		move_bas_gauche(keysym, data);
	}
	else if (keysym == LEFT)
	{
		ft_printf("GAUCHE\n");
		move_bas_gauche(keysym, data);
	}
	else if (keysym == RIGHT)
	{
		ft_printf("DROIT\n");
		move_haut_droite(keysym, data);
	}
	else
		ft_printf("Vous etes hors touche %d\n", keysym);
	return (0);
}
