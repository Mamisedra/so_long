/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 22:57:12 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/11 16:24:31 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ERROR_H
# define MAP_ERROR_H

# include "GetNextLine/get_next_line_bonus.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_map
{
	char			*content;
	int				nb_line;
	struct s_map	*next;
}               t_map;

int check_argument(char arg);
int check_P_or_E(char *map[], char check);
int check_C(char *map[]);
int	check_tence(char *arg[]);

#endif