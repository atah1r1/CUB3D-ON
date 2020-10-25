/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:44:02 by atahiri           #+#    #+#             */
/*   Updated: 2020/02/28 09:32:12 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(void *mlx_ptr, void *win_ptr, int x, int y)
{
    int tmp = y;
    int i = 0;
    int j = 0;
	while (i <= TILE_SIZE)
    { 
        while (j <= TILE_SIZE)
        {
            
            mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFF00);
            j++;
            y++;
        }
        j = 0;
        i++;
        x++;
        y = tmp;
    }
}