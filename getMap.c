/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getMap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 02:54:48 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/18 04:41:21 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "so_long.h"

int notber(char *argv)
{
	int     len;
	int     i;
	char    *ext;

	ext = "reb.";
	i = 0;
	len = ft_strlen(argv) - 1;
	while (i <= 3)
	{
		if (argv[len - i] != ext[i])
			return (0);
		i++;
	}
	return (1);
}

int getMap(int argc, char *argv[])
{
	int fd;

	if (argc == 1 || argc != 2)
		return (0);
	if (!notber(argv[1]))
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
	{
		close (fd);
		return (0);
	}
	return (fd);
}

t_list *ft_copy_to_list(int argc, char *argv[])
{
	t_list	*list;
	char	*line;
	int		fd;

	fd = getMap(argc, argv);
	if (!fd)
	{
		ft_printf("Error\n");
		return (NULL);
	}
	list = NULL;
	while(1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		ft_lstadd_back(&list, ft_lstnew(line));
	}
	close(fd);
	return (list);
}
char	**ft_list_to_tab(int argc, char *argv[])
{
	t_list	*list;
	char	**map;

	list = ft_copy_to_list(argc, argv);
	if (!list)
		exit(EXIT_FAILURE);
	while (list)
	{
		list = list->next;
	}
	return (map);
}