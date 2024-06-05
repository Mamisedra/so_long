/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:49:20 by mranaivo          #+#    #+#             */
/*   Updated: 2024/06/05 11:04:32 by mranaivo         ###   ########.fr       */
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
# include "libft/libft.h"
# include <stdlib.h>
# include "./minilibx-linux/mlx.h"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*none;
	void	*finish;
	void	*start;
	void	*skills;
	void	*victory;
	void	*player;
	void	*player_up[4];
	void	*player_down[4];
	void	*player_rigth[4];
	void	*player_left[4];
	void	*player_attaque[4];
	void	*wall[6];
	void	*stop[4];
	char	**map;
	char	*coll;
	char	*move;
	int		img_height;
	int		img_width;
	int		collect;
	int		x;
	int		y;
	int		e_x;
	int		e_y;
}			t_data;

	// GAME FINISH

int		ft_count_collect(t_data *data);
int		program_quit(t_data *data);
int		ft_escap(int key, t_data *data);
void	you_win(t_data *data, int key);
int		ft_game_not_run(t_list *list);

// MAP INIT

void	ft_startinit(t_data *data);
void	position_swap(t_data *data, int x, int y, char c);

// PERSO_MOVE

int		answer_key(int keysym, t_data *data);
int		move_up(t_data *data, int key);
int		move_down(t_data *data, int key);
int		move_left(t_data *data, int key);
int		move_rigth(t_data *data, int key);

// PERSO_MOVE_UTLIS

void	ft_void(t_data *data, int key);
void	ft_printofkey(t_data *data, int key);

#endif