/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:02:30 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/12 11:25:44 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*newv;

	newv = malloc(sizeof(t_list));
	if (newv)
	{
		newv->content = content;
		newv->next = NULL;
	}
	return (newv);
}
