/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 02:55:29 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/21 15:56:38 by mranaivo         ###   ########.fr       */
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

//FUNCTION ERROR.c LOCATION

int		ft_check_char(t_list *list);
int		ft_check_wall(t_list *list);
int     ft_countline(t_list *list);
int		ft_check_all_error(t_list *list);

//FUNCTION ERROR_UTILS

int		ft_countchar(char *str, char c);
int		ft_check_intru(char *str);
int		ft_strlen_list(char *str);
void	ft_freemap(int i, char **map);
int		ft_check_resolution(t_list *list);
void	ft_free_all(char **map);

//FUNCTION GETMAP.C LOCATION

int		notber(char *argv);
t_list  *ft_copy_to_list(int argc, char *argv[]);
int		ft_game_not_run(t_list *list);
char    **ft_list_to_tab(int argc, char *argv[]);
void	ft_where_P(t_data *data);
void	ft_where_E(t_data *data);
void	ft_change_final(t_data *data, int cd);
void	give_all_pos(t_data *data);
void	you_win(t_data *data, int key);

#endif