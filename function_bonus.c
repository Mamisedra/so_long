/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:46:19 by mranaivo          #+#    #+#             */
/*   Updated: 2024/06/21 13:23:38 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "interface.h"

void	ft_strcpy(t_data *data, char *road_0, char *road_1)
{
	char	*r0_tmp;
	char	*r1_tmp;
	int		i;
	int		j;

	r0_tmp = ft_getroad(data->map, \
	data->enemy_pos_x[0], data->enemy_pos_y[0]);
	r1_tmp = ft_getroad(data->map, \
	data->enemy_pos_x[1], data->enemy_pos_y[1]);
	i = 0;
	while (r0_tmp[i] != '\0' && i < NB_PAS)
	{
		road_0[i] = r0_tmp[i];
		i++;
	}
	road_0[i] = '\0';
	free(r0_tmp);
	j = 0;
	while (r1_tmp[j] != '\0' && j < NB_PAS)
	{
		road_1[j] = r1_tmp[j];
		j++;
	}
	road_1[j] = '\0';
	free(r1_tmp);
}

void	print_all(t_data *data)
{
	char	*a;

	a = ft_itoa(data->nb_pas);
	data->move = ft_strjoin_g(ft_strdup("Move : "), a);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 55, BLUE, data->move);
	free(data->move);
	free(a);
	a = ft_itoa(data->collect);
	data->coll = ft_strjoin_g(ft_strdup("Adversaire : "), a);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 30, BLUE, data->coll);
	free(data->coll);
	free(a);
}

int	move(t_data *data)
{
	static int	i = 0;
	static int	rd = 0;

	if (rd == 0)
	{
		initialize_roads(data);
		rd = 1;
	}
	if (rd == 1)
	{
		if (i < NB_PAS + 1)
			move_forward(data, &i);
		if (i == NB_PAS + 1)
			rd = 2;
	}
	if (rd == 2)
	{
		if (i > 0)
			move_backward(data, &i);
		if (i == 0)
			rd = 1;
	}
	usleep(50000);
	ft_print_begin(data, data->map, data->player);
	return (print_all(data), 0);
}
