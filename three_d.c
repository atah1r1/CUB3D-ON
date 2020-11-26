/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:58:40 by atahiri           #+#    #+#             */
/*   Updated: 2020/11/26 10:08:56 by atahiri          ###   ########.fr       */
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

int		get_tx(int i)
{
	int	tx;

	tx = 0;
	if (!g_ray[i].hit_ver && g_ray[i].wall_face_up)
		tx = 0;
	else if (!g_ray[i].hit_ver && g_ray[i].wall_face_down)
		tx = 1;
	else if (g_ray[i].hit_ver && g_ray[i].wall_face_right)
		tx = 2;
	else if (g_ray[i].hit_ver && g_ray[i].wall_face_left)
		tx = 3;
	return (tx);
}

void	texture_offset(int i)
{
	if (g_ray[i].hit_ver)
		g_threed.txt_off_x = (int)g_ray[i].wall_hit_y % TILE_SIZE;
	else
		g_threed.txt_off_x = (int)g_ray[i].wall_hit_x % TILE_SIZE;
	g_threed.txt_off_x = g_threed.txt_off_x >= TILE_SIZE ? TILE_SIZE - 1 :
			g_threed.txt_off_x;
}

void	wall_bottom_px(int i, int j)
{
	g_threed.dist_from_top = (float)j + (g_threed.prj_wall_h / 2.0F) -
		((float)g_data->w_height / 2.0F);
	g_threed.txt_off_y = g_threed.dist_from_top *
		((float)TILE_SIZE / g_threed.prj_wall_h);
	g_threed.txt_off_y = g_threed.txt_off_y >= TILE_SIZE ? TILE_SIZE - 1 :
		g_threed.txt_off_y;
	g_threed.texelcolor = g_texture[get_tx(i)].color
		[(TILE_SIZE * g_threed.txt_off_y) + g_threed.txt_off_x];
	g_data->matrix3d[(g_data->w_width * j) + i] = g_threed.texelcolor;
}

void	three_d(void)
{
	int			i;
	int			j;

	i = 0;
	while (i < g_data->w_width)
	{
		j = 0;
		calculating(i);
		while (j < g_threed.wall_tp_px)
			g_data->matrix3d[(g_data->w_width * j++) + i] =
				handle_color(&(g_data->ceil));
		texture_offset(i);
		while (j < g_threed.wall_bottom_px)
			wall_bottom_px(i, j++);
		while (j < g_data->w_height)
			g_data->matrix3d[(g_data->w_width * j++) + i] =
				handle_color(&(g_data->floor));
		i++;
	}
}
