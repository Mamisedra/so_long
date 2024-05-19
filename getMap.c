/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getMap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 02:54:48 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/19 16:19:25 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			return (1);
		i++;
	}
	return (0);
}

t_list *ft_copy_to_list(int argc, char *argv[])
{
	t_list	*list;
	char	*line;
	int		fd;

	if (argc == 1 || argc != 2 || notber(argv[1]))
	{
		ft_printf("Error: Probleme d'argument\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
	{
		ft_printf("Probleme de lecture de fichier");
		exit(EXIT_FAILURE);
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

int		ft_game_not_run(t_list *list)
{
	if (ft_check_char(list))
	{
		ft_printf("Error: Probleme interne des characteres (P,E,C)\n");
		return (1);
	}
	else if (ft_check_all_error(list))
	{
		ft_printf("Error: Map n'est pas rectangles\n");
		return (1);
	}
	else if (ft_check_wall(list))
	{
		ft_printf("Error: Map n'est pas entourrer des murs\n");
		return (1);
	}
	return (0);
}

char	**ft_list_to_tab(int argc, char *argv[])
{
	t_list	*list;
	char	**map;
	int		i;

	if (ft_game_not_run(list))
		exit(EXIT_FAILURE);
	list = NULL;
	list = ft_copy_to_list(argc, argv);
	map = (char **) malloc(( sizeof(char *) * ft_countline(list)) + 1);
	if (!map)
		return (NULL);
	i = 0;
	while (list)
	{
		map[i] = ft_strdup(list->content);
		if (!map[i])
			ft_freemap(i, map);
		list = list->next;
		i++;
	}
	map[i] = NULL;
	ft_lstclear(&list, free);
	return (map);
}
