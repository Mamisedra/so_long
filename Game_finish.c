/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game_finish.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:01:05 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/29 16:43:59 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

int	ft_game_not_run(t_list *list)
{
	if (ft_check_char(list))
		ft_printf("Error: Probleme interne des characteres (P,E,C)\n");
	else if (ft_check_all_error(list))
		ft_printf("Error: Map n'est pas rectangles\n");
	else if (ft_check_wall(list))
		ft_printf("Error: Map n'est pas entourrer des murs\n");
	else if (ft_check_resolution(list))
		ft_printf("Error: Resolution non valide(>%dx%d)\n", HEIGTH, WIDTH);
	else
		return (0);
	ft_lstclear(&list, free);
	return (1);
}

int	program_quit(t_data *data)
{
	ft_destroy_img(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_loop_end(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
	ft_free_all(data->map);
	free(data->mlx_ptr);
	free(data);
	exit(EXIT_SUCCESS);
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

int	ft_escap(int key, t_data *data)
{
	if (key == ESC)
		program_quit(data);
	return (0);
}

void	you_win(t_data *data, int key)
{
	int	x;
	int	y;

	x = data->x;
	y = data->y;
	if (key == RIGHT)
	{
		if (data->map[y][x + 1] == 'E')
			program_quit(data);
	}
	else if (key == UP)
	{
		if (data->map[y - 1][x] == 'E')
			program_quit(data);
	}
	else if (key == LEFT)
	{
		if (data->map[y][x - 1] == 'E')
			program_quit(data);
	}
	else if (key == DOWN)
	{
		if (data->map[y + 1][x] == 'E')
			program_quit(data);
	}
}
