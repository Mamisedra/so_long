/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 06:54:07 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/11 16:27:55 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int main()
// {
//     int fd = open("./map/map_1.ber", O_RDONLY);
//     char *test = get_next_line(fd);
//     ft_printf("%s", test);
//     close(fd);
// }

int     main(int argc, char *argv[])
{
    printf("%d", argc);
    int i = 0;
    while (i < argc)
    {
        printf("%s", argv[i]);
        i++;
    }
    return (0);
}