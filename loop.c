/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 23:26:13 by atahiri           #+#    #+#             */
/*   Updated: 2020/11/29 17:19:38 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		loop(void)
{
	move_player();
	cast_rays();
	three_d();
	draw_sprites();
	mlx_put_image_to_window(g_data->ptr, g_data->win, g_data->image3d, 0, 0);
	return (0);
}
