/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:31:19 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/11 10:58:39 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

int		ft_strlen_g(char *str);
int		ft_strchr_g(char *store, char c);

char	*ft_strjoin_g(char *s1, char *s2);
char	*ft_extracteline(char *store);
char	*ft_getreste(char *store);
char	*ft_read(char *reste, int fd);
char	*get_next_line(int fd);
char	*ft_strdup_g(char *buffer);

void	ft_strcpy_g(char *store, char *reste);

#endif
