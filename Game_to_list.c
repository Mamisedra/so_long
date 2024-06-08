/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game_to_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:50:44 by mranaivo          #+#    #+#             */
/*   Updated: 2024/06/08 14:41:24 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minilibx-linux/mlx.h"
#include "so_long.h"

int	ft_countline(t_list *list)
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

char	**ft_list_to_tab(int argc, char *argv[])
{
	t_list	*list;
	t_list	*tmp;
	char	**map;
	int		i;

	list = ft_copy_to_list(argc, argv);
	if (ft_game_not_run(list) || !list)
		exit(EXIT_FAILURE);
	map = (char **)malloc(sizeof(char *) * (ft_countline(list) + 1));
	if (!map)
		return (NULL);
	i = 0;
	tmp = list;
	while (list)
	{
		map[i] = ft_strdup(list->content);
		if (!map[i])
			return (ft_freemap(i, map), ft_lstclear(&tmp, free), NULL);
		list = list->next;
		i++;
	}
	map[i] = NULL;
	return (ft_lstclear(&tmp, free), map);
}

t_list	*ft_copy_to_list(int argc, char *argv[])
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
		ft_printf("Error: Probleme de lecture de fichier\n");
		exit(EXIT_FAILURE);
	}
	list = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		ft_lstadd_back(&list, ft_lstnew(line));
	}
	close(fd);
	return (free(line), list);
}

void	ft_free_img(t_data *data, void **img, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		mlx_destroy_image(data->mlx_ptr, img[i]);
		i++;
	}
}

void	ft_destroy_img(t_data *data)
{
	ft_free_img(data, data->player_up, 4);
	ft_free_img(data, data->player_down, 4);
	ft_free_img(data, data->player_rigth, 4);
	ft_free_img(data, data->player_left, 4);
	ft_free_img(data, data->player_attaque, 4);
	ft_free_img(data, data->stop, 4);
	ft_free_img(data, data->wall, 6);
	mlx_destroy_image(data->mlx_ptr, data->none);
	mlx_destroy_image(data->mlx_ptr, data->skills);
	mlx_destroy_image(data->mlx_ptr, data->finish);
	mlx_destroy_image(data->mlx_ptr, data->start);
	mlx_destroy_image(data->mlx_ptr, data->player);
	mlx_destroy_image(data->mlx_ptr, data->enemy_left);
	mlx_destroy_image(data->mlx_ptr, data->enemy_right);
}
