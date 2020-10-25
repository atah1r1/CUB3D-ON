/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:58:40 by atahiri           #+#    #+#             */
/*   Updated: 2020/10/25 10:50:18 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	three_d(void)
{
	int			i;
	int			j;
	int floor_color;
	int ciel_color;

	floor_color = handle_color(&(g_data->floor));
	ciel_color = handle_color(&(g_data->ceil));
	i = 0;
	while (i < g_data->w_width)
	{
		j = 0;
		int tx;
		threed.cor_distance = g_ray[i].distance * cosf(g_ray[i].ray_angle - g_player->angle);
		threed.dis_proj_pln = (g_data->w_width / 2) / tanf(FOV_ANGLE / 2);
		threed.prj_wall_h = (TILE_SIZE / (threed.cor_distance == 0 ? 0.1 : threed.cor_distance)) * threed.dis_proj_pln;
		threed.wall_tp_px = (g_data->w_height / 2) - (threed.prj_wall_h / 2);
		threed.wall_tp_px = threed.wall_tp_px < 0 ? 0 : threed.wall_tp_px;
		threed.wall_bottom_px = (g_data->w_height / 2) + (threed.prj_wall_h / 2);
		threed.wall_bottom_px = threed.wall_bottom_px > g_data->w_height ? g_data->w_height : threed.wall_bottom_px;
		while (j < threed.wall_tp_px)
			g_data->matrix3d[(g_data->w_width * j++) + i] = ciel_color;
		int textureOffsetX;
        if (g_ray[i].hit_ver)
            textureOffsetX = (int)g_ray[i].wall_hit_y % TILE_SIZE;
        else
            textureOffsetX = (int)g_ray[i].wall_hit_x % TILE_SIZE;
		textureOffsetX = textureOffsetX >= TILE_SIZE ? TILE_SIZE - 1 : textureOffsetX;
        while (j < threed.wall_bottom_px) 
		{
			if (!g_ray[i].hit_ver && g_ray[i].wall_facing_up)
            tx = 0;
        	else if (!g_ray[i].hit_ver && g_ray[i].wall_facing_down)
            tx = 1;
        	else if (g_ray[i].hit_ver  && g_ray[i].wall_facing_right)
            tx = 2;
        	else if (g_ray[i].hit_ver  && g_ray[i].wall_facing_left)
            tx = 3;
            float distanceFromTop = (float)j + (threed.prj_wall_h  / 2.0F) - ((float)g_data->w_height / 2.0F);
            int textureOffsetY = distanceFromTop * ((float)TILE_SIZE / threed.prj_wall_h);
			textureOffsetY = textureOffsetY >= TILE_SIZE ? TILE_SIZE-1 : textureOffsetY;
            int texelColor = texture[tx].color[(TILE_SIZE * textureOffsetY) + textureOffsetX];
            g_data->matrix3d[(g_data->w_width * j++) + i] = texelColor;
        }
		while (j < g_data->w_height)
			g_data->matrix3d[(g_data->w_width * j++) + i] = floor_color;
		i++;
	}
}