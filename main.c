/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:26:08 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/29 16:04:59 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"
#include "minilibx-linux/mlx.h"
#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		exit(EXIT_FAILURE);
	data->map = ft_list_to_tab(argc, argv);
	give_all_pos(data);
	ft_startinit(data);
	input_image(data);
	mlx_key_hook(data->win_ptr, answer_key, data);
	mlx_hook(data->win_ptr,17,1L<<17, program_quit, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

// int	main()
// {
// 	t_data	*data;

// 	data = (t_data *)malloc(sizeof(t_data) * 1);
// 	if (!data)
// 		exit(EXIT_FAILURE);
// 	data->mlx_ptr = mlx_init();
// 	if (!data->mlx_ptr)
// 		exit(EXIT_FAILURE);
// 	mlx_destroy_display(data->mlx_ptr);
// 	free(data->mlx_ptr);
// 	free(data);
// 	return (0);
// }

// int	main()
// {
// 	t_data	*data;

// 	data = (t_data *)malloc(sizeof(t_data));
// 	if (!data)
// 		exit(EXIT_FAILURE);
// 	ft_startinit(data);
// 	mlx_hook(data->win_ptr,17,1L<<17, program_quit, data);
// 	mlx_key_hook(data->win_ptr, answer_key, data);
// 	mlx_loop(data->mlx_ptr);
// 	return (0);
// }

// int main()
// {
// 	t_data *data;
// 	data->mlx_ptr = mlx_init();
// 	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGTH, "jeu");
// 	input_go_rigth(data);
// 	input_go_left(data);
// 	input_go_up(data);
// 	input_go_down(data);
// 	show_anim(data->player_rigth, data, 0, 0);
// 	show_anim(data->player_left, data, 64, 0);
// 	show_anim(data->player_up, data, 128, 0);
// 	show_anim(data->player_down, data, 192, 0);
// 	show_anim(data->player_attaque, data, 232, 0);
// 	mlx_loop(data->mlx_ptr);
// 	return (0);
// }

// int	main(int argc, char *argv[])
// {
// 	char	**map;

// 	map = ft_list_to_tab(argc, argv);
// 	if (map == NULL)
// 		exit(EXIT_FAILURE);
// 	// ft_lstclear(&list, free);
// 	for (int i = 0; i < 8; i++)
// 		ft_printf("%s",map[i]);
// 	ft_printf("\n");
// 	ft_free_all(map);
// }
