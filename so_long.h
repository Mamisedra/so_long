/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 02:55:29 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/28 20:32:29 by mranaivo         ###   ########.fr       */
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

//GAME_TO_LIST

int		ft_countline(t_list *list);
t_list	*ft_copy_to_list(int argc, char *argv[]);
char	**ft_list_to_tab(int argc, char *argv[]);
void	ft_free_img(t_data *data, void **img);
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

void	ft_print_begin(t_data *data, char **map);
int	    ft_countline_map(char **map);
void	input_stop(t_data *data);
void	input_wall(t_data *data);
void	show_anim(void **image, t_data *data, int x, int y);

#endif