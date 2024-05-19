/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:26:08 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/19 16:20:14 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"
#include "so_long.h"

 int	main(int argc, char *argv[])
 {
 	t_data	*data;
	char	**map;

	t_list *list = ft_copy_to_list(argc, argv);
	ft_game_not_run(list);
 	// input_image(data);
	// mlx_key_hook(data->win_ptr, answer_key,data);
 	// mlx_hook(data->win_ptr,17,1L<<17, program_quit, data);
 	// mlx_loop(data->mlx_ptr);
 	return (0);
 }