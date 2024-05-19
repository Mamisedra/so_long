/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:49:38 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/19 15:55:56 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"
#include "minilibx-linux/mlx.h"

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
int	move_image(t_data *data, void *image, int key)
{
	t_move	*move;
	move->x = 0;
	move->y = 0;
	if (key == UP)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, image, move->x, move->y-64);
	else if (key == DOWN)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, image, move->x, move->y+64);
	else if (key == LEFT)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, image, move->x-64, move->y);
	else if (key == RIGHT)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, image, move->x+64, move->y);
	return (1);
}
int answer_key(int keysym, t_data *data)
{
	int	i;
	if (keysym == ESC)
		program_quit(data);
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