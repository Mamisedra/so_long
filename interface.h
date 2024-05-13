/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:49:20 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/13 15:45:20 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_H
# define INTERFACE_H

# define ESC 65307
# define LEFT 97
# define RIGHT 100
# define UP 119
# define DOWN 115

#include "ft_printf/ft_printf.h"
#include <stdlib.h>
#include "./minilibx-linux/mlx.h"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

int	program_quit(t_data *data);
int	ft_escap(int key, t_data *data);

#endif