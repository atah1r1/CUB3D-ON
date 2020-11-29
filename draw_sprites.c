/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 17:38:25 by atahiri           #+#    #+#             */
/*   Updated: 2020/11/29 19:11:17 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	coloring_sprite(int offset_x, int offset_y, int x, int y)
{
	g_data->matrix3d[(offset_y + y) * g_data->w_width + (offset_x + x)] =
		g_texture[4].color[g_texture[4].colors];
}

void	render_sprite(int s_index, int offset_x, int offset_y)
{
	int			x;
	int			y;
	const float	ratio = g_texture[4].width / g_sprite[s_index].size;

	x = -1;
	while (++x < (int)g_sprite[s_index].size)
	{
		if (offset_x + x < 0 || offset_x + x >= g_data->w_width)
			continue ;
		if (g_ray[offset_x + x].distance <= g_sprite[s_index].dist)
			continue ;
		y = -1;
		g_sprite->rsx = (x * ratio);
		while (++y < (int)g_sprite[s_index].size)
		{
			if (offset_y + y < 0 || offset_y + y >= g_data->w_height)
				continue ;
			g_sprite->rsy = (y * ratio);
			g_texture[4].colors = (g_sprite->rsy * g_texture[4].width + g_sprite->rsx);
			if (g_texture[4].color[g_texture[4].colors] != g_texture[4].color[0])
				coloring_sprite(offset_x, offset_y, x, y);
		}
	}
}

void	sort_sprites(void)
{
	int			i;
	int			j;
	int			sprs_nb;
	t_sprite	spr_tmp;

	i = -1;
	sprs_nb = g_num_sprites;
	while (++i < g_num_sprites)
	{
		j = -1;
		while (++j + 1 < sprs_nb)
			if (g_sprite[j].dist < g_sprite[j + 1].dist)
			{
				spr_tmp = g_sprite[j + 1];
				g_sprite[j + 1] = g_sprite[j];
				g_sprite[j] = spr_tmp;
			}
		--sprs_nb;
	}
}

void	draw_sprites(void)
{
	int		i;
	float	sp_pplane;

	sp_pplane = (g_data->w_width / 2.0F) / tanf((FOV_ANGLE) / 2);
	i = 0;
	while (i < g_num_sprites)
	{
		g_sprite[i].dist = distance_between_points(g_sprite[i].x, g_sprite[i].y, g_player->x, g_player->y);
		g_sprite[i].angle = atan2f(g_sprite[i].y - g_player->y, g_sprite[i].x - g_player->x);
		g_sprite[i].angle = normalize_sprite(g_sprite[i].angle);
		g_sprite[i].size = (TILE_SIZE / g_sprite[i].dist * sp_pplane);
		g_sprite[i].y_off = (g_data->w_height / 2.0F) - (g_sprite[i].size / 2);
		g_sprite[i].x_off = (((DEG(g_sprite[i].angle) - DEG(g_player->angle)) * g_data->w_width) / (g_texture[4].width) + ((g_data->w_width / 2.0F) - (g_sprite[i].size / 2)));
		i++;
	}
	sort_sprites();
	i = -1;
	while (++i < g_num_sprites)
		render_sprite(i, g_sprite[i].x_off, g_sprite[i].y_off);
}