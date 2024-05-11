/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 08:53:47 by mranaivo          #+#    #+#             */
/*   Updated: 2024/03/03 08:53:50 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*mem;
	int		i;

	i = 0;
	mem = malloc (count * size);
	if (!mem)
		return (NULL);
	while (mem[i] != '\0')
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}
