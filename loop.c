/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 23:26:13 by atahiri           #+#    #+#             */
/*   Updated: 2020/12/04 17:21:24 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		loop(void)
{
	cast_rays();
	three_d();
	draw_sprites();
	move_player();
	if (save_found == 1)
	{
		bmp_file();
		exit(0);
	}
	mlx_put_image_to_window(g_data->ptr, g_data->win, g_data->image3d, 0, 0);
	return (0);
}
