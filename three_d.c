/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:58:40 by atahiri           #+#    #+#             */
/*   Updated: 2020/11/22 13:13:01 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculating(int i)
{
	g_threed.cor_distance = g_ray[i].distance *
		cosf(g_ray[i].ray_angle - g_player->angle);
	g_threed.dis_proj_pln = (g_data->w_width / 2) / tanf(FOV_ANGLE / 2);
	g_threed.prj_wall_h = (TILE_SIZE / (g_threed.cor_distance == 0 ? 0.1
		: g_threed.cor_distance)) * g_threed.dis_proj_pln;
	g_threed.wall_tp_px = (g_data->w_height / 2) - (g_threed.prj_wall_h / 2);
	g_threed.wall_tp_px = g_threed.wall_tp_px < 0 ? 0 : g_threed.wall_tp_px;
	g_threed.wall_bottom_px = (g_data->w_height / 2) +
		(g_threed.prj_wall_h / 2);
	g_threed.wall_bottom_px = g_threed.wall_bottom_px > g_data->w_height ?
		g_data->w_height : g_threed.wall_bottom_px;
}

int	get_tx(int i)
{
	int	tx;

	if (!g_ray[i].hit_ver && g_ray[i].wall_facing_up)
		tx = 0;
	else if (!g_ray[i].hit_ver && g_ray[i].wall_facing_down)
		tx = 1;
	else if (g_ray[i].hit_ver  && g_ray[i].wall_facing_right)
		tx = 2;
	else if (g_ray[i].hit_ver  && g_ray[i].wall_facing_left)
		tx = 3;
	return (tx);
}

void	three_d(void)
{
	int			i;
	int			j;
	float		dist_from_top;
	int			txt_off_y;
	int			txt_off_x;
	int			texelcolor;

	i = 0;
	while (i < g_data->w_width)
	{
		j = 0;
		calculating(i);
		while (j < g_threed.wall_tp_px)
			g_data->matrix3d[(g_data->w_width * j++) + i] = handle_color(&(g_data->ceil));
		if (g_ray[i].hit_ver)
			txt_off_x = (int)g_ray[i].wall_hit_y % TILE_SIZE;
		else
			txt_off_x = (int)g_ray[i].wall_hit_x % TILE_SIZE;
		txt_off_x = txt_off_x >= TILE_SIZE ? TILE_SIZE - 1 : txt_off_x;
		while (j < g_threed.wall_bottom_px)
		{
				dist_from_top = (float)j + (g_threed.prj_wall_h  / 2.0F) -
								((float)g_data->w_height / 2.0F);
				txt_off_y = dist_from_top * ((float)TILE_SIZE / g_threed.prj_wall_h);
				txt_off_y = txt_off_y >= TILE_SIZE ? TILE_SIZE - 1 : txt_off_y;
				texelcolor = g_texture[get_tx(i)].color[(TILE_SIZE * txt_off_y) + txt_off_x];
				g_data->matrix3d[(g_data->w_width * j++) + i] = texelcolor;
		}
		while (j < g_data->w_height)
			g_data->matrix3d[(g_data->w_width * j++) + i] = handle_color(&(g_data->floor));
		i++;
	}
}
