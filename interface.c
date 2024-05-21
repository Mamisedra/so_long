/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:49:38 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/21 15:56:47 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"
#include "ft_printf/ft_printf.h"
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
	static int	i = 0;

	if (keysym == ESC)
		program_quit(data);
	if (keysym == UP)
		i += move_haut_droite(keysym, data);
	else if (keysym == DOWN)
		i += move_bas_gauche(keysym, data);
	else if (keysym == LEFT)
		i += move_bas_gauche(keysym, data);
	else if (keysym == RIGHT)
		i += move_haut_droite(keysym, data);
	if (data->map[data->y][data->x] != '1')
		ft_printf("Nbre de pas : %d\n", i);
	ft_printf("Collecte : %d\n", data->collect);
	if (data->collect == 0)
	{
		ft_change_final(data, 1);
		ft_printmap_rigth(data, data->map);
		you_win(data, keysym);
	}
	return (0);
}

int	ft_count_collect(t_data *data)
{
	int	i;
	int	cpt;

	cpt = 0;
	i = 0;
	while (data->map[i] != NULL)
	{
		cpt += ft_countchar(data->map[i], 'C');
		i ++;
	}
	return (cpt);
}

void	give_all_pos(t_data *data)
{
	ft_where_P(data);
	ft_where_E(data);
	ft_change_final(data, -1);
}

void	you_win(t_data *data, int key)
{
	int	x;
	int	y;

	x = data->x;
	y = data->y;
	if(key == RIGHT)
	{
		if(data->map[y][x + 1] == 'E')
			program_quit(data);
	}
	else if(key == UP)
	{
		if(data->map[y - 1][x] == 'E')
			program_quit(data);
	}
	else if(key == LEFT)
	{
		if(data->map[y][x - 1] == 'E')
			program_quit(data);
	}
	else if(key == DOWN)
	{
		if(data->map[y + 1][x] == 'E')
			program_quit(data);
	}
}
