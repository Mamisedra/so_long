/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_and_key.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:07:38 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/11 15:41:33 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_getwidth(void)
{
    int width;

    width = 100;
    return (width);
}

int ft_getheigth(void)
{
    int heigth;

    heigth = 120;
    return (heigth);
}

int main(void)
{
    void    *mlx;
    void    *mlx_win;
    int     width;
    int     heigth;

    width = ft_getwidth();
    heigth = ft_getheigth();
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, width, heigth, "hello world!");
    mlx_loop(mlx);
}
