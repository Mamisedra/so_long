/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:49:20 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/21 15:28:23 by mranaivo         ###   ########.fr       */
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
# define WIDTH 1920
# define HEIGTH 1080

# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include "./minilibx-linux/mlx.h"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	void	*none;
	void	*finish;
	void	*player_G;
	void	*player_D;
	void	*start;
	void	*skills;
	void	*stop;
	int		img_height;
	int		img_width;
	char	**map;
	int		collect;
	int		x;
	int		y;
	int		E_x;
	int		E_y;
}	t_data;

int		move_bas_gauche(int key, t_data *data);
int		move_haut_droite(int key, t_data *data);
int		ft_count_collect(t_data *data);

int		program_quit(t_data *data);
int		ft_escap(int key, t_data *data);
int 	answer_key(int keysym, t_data *data);
void 	ft_startinit(t_data *data);
void	input_image(t_data *data);

void	ft_printmap_rigth(t_data *data, char **map);
void	ft_printmap_left(t_data *data, char **map);

#endif