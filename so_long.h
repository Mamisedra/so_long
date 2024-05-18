/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 02:55:29 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/18 03:13:13 by mranaivo         ###   ########.fr       */
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

int	notber(char *argv);
int getMap(int argc, char *argv[]);
int check_list(int argc, char *argv[]);

#endif