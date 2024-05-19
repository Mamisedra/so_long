/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:57:43 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/19 17:36:15 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_wall(t_list *list)
{
	int	i;
	int	j;
	int	listlength;

	listlength = ft_countline(list);
	while (list)
	{
		if (i == 0 || i == listlength)
		{
			j = 0;
			while(list->content[j] == '1')
				j++;
			if (j != ft_strlen(list->content))
				return (1);
		}
		if (list->content[0] != '1' || list->content[ft_strlen(list->content)] != '1')
			return (1);
		i++;
		list = list->next;
	}
	return (0);
}

int	ft_check_char(t_list *list)
{
	int	c;
	int	p;
	int	e;

	c = 0;
	p = 0;
	e = 0;
	while (list)
	{
		c += ft_countchar(list->content, 'C');
		p += ft_countchar(list->content, 'P');
		e += ft_countchar(list->content, 'E');
		list = list->next;
	}
	if (c < 1 || p != 1 || e != 1)
		return (1);
	return (0);
}

int		ft_countline(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

int	ft_check_all_error(t_list *list)
{
	int	lentmp;
	int	lenlast;

	lenlast = ft_check_intru(list->content);
	while (list)
	{
		lentmp = ft_check_intru(list->content);
		if (lentmp != lenlast || ft_check_intru(list->content))
			return (1);
		list = list->next;
	}
	return (0);
}