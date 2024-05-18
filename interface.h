/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:49:20 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/18 03:13:12 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_H
# define INTERFACE_H

# define ESC 65307
# define LEFT 97
# define RIGHT 100
# define UP 119
# define DOWN 115
# define BLUE 0x32BDD2
# define RED 0xAB1212
# define WIDTH 700
# define HEIGTH 450

# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include "./minilibx-linux/mlx.h"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
}	t_data;

typedef struct s_move
{
	int	x;
	int	y;
}	t_move;

int		program_quit(t_data *data);
int		ft_escap(int key, t_data *data);
int 	answer_key(int keysym, t_data *data);
void 	ft_startinit(t_data *data);
int		input_image(t_data *data);
int	move_image(t_data *data, void *image, int key);

#endif