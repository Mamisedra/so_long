/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 02:55:29 by mranaivo          #+#    #+#             */
/*   Updated: 2024/06/21 13:05:01 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "interface.h"
# include "libft/libft.h"
# include "GetNextLine/get_next_line_bonus.h"
# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

//==============================BONUS====================================
char	*ft_getroad(char **map, int pos_x, int pos_y);
int		move(t_data *data);
void	ft_strcpy(t_data *data, char *road_0, char *road_1);
void	move_backward(t_data *data, int *i);
void	move_forward(t_data *data, int *i);
void	initialize_roads(t_data *data);
char	*ft_getroad(char **map, int pos_x, int pos_y);
char	get_next_move(char **map, int *pos_x, int *pos_y, char last_move);
void	move_go(t_data *data, int *pos_x, int *pos_y, char c);
void	move_back(t_data *data, int *pos_x, int *pos_y, char c);
void	print_all(t_data *data);

void	place_enemy(t_data *data);
void	place_define(t_data *data);
void	place_enemy_final(char **map, int heigth, int width);
int		gameover(t_data *data);
void	place_enemy_2(t_data *data);
int		move(t_data *data);
void	show_move(char **map, int pos_x, int pos_y, int i);
void	move_enemy_1(t_data *data, char **map, int pos_x, int pos_y);

//GAME_TO_LIST

int		ft_countline(t_list *list);
t_list	*ft_copy_to_list(int argc, char *argv[]);
char	**ft_list_to_tab(int argc, char *argv[]);
void	ft_free_img(t_data *data, void **img, int max);
void	ft_destroy_img(t_data *data);

//MAP_ERROR_UTILS

int		ft_countchar(char *str, char c);
int		ft_check_intru(char *str);
int		ft_strlen_list(char *str);
void	ft_freemap(int i, char **map);
void	ft_free_all(char **map);

//MAP_ERROR

int		ft_check_resolution(t_list *list);
int		notber(char *argv);
int		ft_check_char(t_list *list);
int		ft_check_wall(t_list *list);
int		ft_check_all_error(t_list *list);

//PLAYER_POS

void	ft_change_final(t_data *data, int cd);
void	give_all_pos(t_data *data);
void	ft_where_p(t_data *data);
void	ft_where_e(t_data *data);

//INPUT_IMAGE :

void	input_image(t_data *data);
void	input_go_rigth(t_data *data);
void	input_go_up(t_data *data);
void	input_go_down(t_data *data);
void	input_go_left(t_data *data);

// add_utils:

void	ft_map_print(t_data *data, char **map, int heigth, int width);
void	ft_print_begin(t_data *data, char **map, void *show);
int		ft_countline_map(char **map);
void	input_stop(t_data *data);
void	input_wall(t_data *data);
void	show_anim(void **image, t_data *data, int x, int y);

//MAP_acces:

void	police_of_game(char **map, int x, int y, int **visite);
int		**get_visit(int heigth, int width);
int		access_chr(char **map, int heigth, int width, int **visite);
void	check_all_access(t_data *data);

//Map_print_utils:

void	ft_add_map_print(t_data *data, char **map, int heigth, int width);
void	ft_add_print_begin(t_data *data, void *show, int heigth, int width);
int		ft_count_obs(char **map);

#endif