/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:18:55 by atahiri           #+#    #+#             */
/*   Updated: 2020/11/23 12:44:53 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	horizontal_wall_hint(int s_id)
{
	g_ray->y_intercept = floor(g_player->y / TILE_SIZE) * TILE_SIZE;
	g_ray->y_intercept += g_ray[s_id].wall_face_down ? TILE_SIZE : 0;
	g_ray->x_intercept = g_player->x + (g_ray->y_intercept - g_player->y) /
		tan(g_ray[s_id].ray_angle);
	g_ray->ystep = TILE_SIZE;
	g_ray->ystep *= g_ray[s_id].wall_face_up ? -1 : 1;
	g_ray->xstep = TILE_SIZE / tan(g_ray[s_id].ray_angle);
	g_ray->xstep *= (g_ray[s_id].wall_face_left && g_ray->xstep > 0) ? -1 : 1;
	g_ray->xstep *= (g_ray[s_id].wall_face_right && g_ray->xstep < 0) ? -1 : 1;
	g_ray->next_horz_x = g_ray->x_intercept;
	g_ray->next_horz_y = g_ray->y_intercept;
	while (g_ray->next_horz_x >= 0 && g_ray->next_horz_y >= 0)
	{
		if (wall_check(g_ray->next_horz_x, g_ray[s_id].wall_face_up ?
			g_ray->next_horz_y - 1 : g_ray->next_horz_y))
		{
			g_ray->found_horz_wall = 1;
			g_ray->wall_horz_hit_x = g_ray->next_horz_x;
			g_ray->wall_horz_hit_y = g_ray->next_horz_y;
			break ;
		}
		g_ray->next_horz_x += g_ray->xstep;
		g_ray->next_horz_y += g_ray->ystep;
	}
}

void	vertical_wall_hint(int s_id)
{
	g_ray->x_intercept = floor(g_player->x / TILE_SIZE) * TILE_SIZE;
	g_ray->x_intercept += g_ray[s_id].wall_face_right ? TILE_SIZE : 0;
	g_ray->y_intercept = g_player->y + (g_ray->x_intercept - g_player->x) *
		tan(g_ray[s_id].ray_angle);
	g_ray->xstep = TILE_SIZE;
	g_ray->xstep *= g_ray[s_id].wall_face_left ? -1 : 1;
	g_ray->ystep = TILE_SIZE * tan(g_ray[s_id].ray_angle);
	g_ray->ystep *= (g_ray[s_id].wall_face_up && g_ray->ystep > 0) ? -1 : 1;
	g_ray->ystep *= (g_ray[s_id].wall_face_down && g_ray->ystep < 0) ? -1 : 1;
	g_ray->next_vert_x = g_ray->x_intercept;
	g_ray->next_vert_y = g_ray->y_intercept;
	while (g_ray->next_vert_x >= 0 && g_ray->next_vert_y >= 0)
	{
		if (wall_check(g_ray[s_id].wall_face_left ?
			g_ray->next_vert_x - 1 : g_ray->next_vert_x, g_ray->next_vert_y))
		{
			g_ray->found_vert_wall = 1;
			g_ray->wall_vert_hit_x = g_ray->next_vert_x;
			g_ray->wall_vert_hit_y = g_ray->next_vert_y;
			break ;
		}
		g_ray->next_vert_x += g_ray->xstep;
		g_ray->next_vert_y += g_ray->ystep;
	}
}

void	calculating_directions(int s_id)
{
	g_ray[s_id].ray_angle = normalize_angle(g_ray[s_id].ray_angle);
	g_ray[s_id].wall_face_down = g_ray[s_id].ray_angle > 0 &&
		g_ray[s_id].ray_angle < M_PI;
	g_ray[s_id].wall_face_up = !g_ray[s_id].wall_face_down;
	g_ray[s_id].wall_face_right = g_ray[s_id].ray_angle < 0.5 * M_PI
		|| g_ray[s_id].ray_angle > 1.5 * M_PI;
	g_ray[s_id].wall_face_left = !g_ray[s_id].wall_face_right;
	g_ray[s_id].hit_ver = 0;
}

void	calculating_x_y(int s_id)
{
	g_ray[s_id].wall_hit_x =
		(g_ray->horz_hit_distance < g_ray->vert_hit_distance)
		? g_ray->wall_horz_hit_x
		: g_ray->wall_vert_hit_x;
	g_ray[s_id].wall_hit_y =
		(g_ray->horz_hit_distance < g_ray->vert_hit_distance)
		? g_ray->wall_horz_hit_y
		: g_ray->wall_vert_hit_y;
	g_ray[s_id].distance =
		(g_ray->horz_hit_distance < g_ray->vert_hit_distance)
		? g_ray->horz_hit_distance
		: g_ray->vert_hit_distance;
	g_ray[s_id].hit_ver = (g_ray->vert_hit_distance < g_ray->horz_hit_distance);
}

void	handle_rays(int s_id)
{
	initialize_rays();
	calculating_directions(s_id);
	horizontal_wall_hint(s_id);
	g_ray->horz_hit_distance = (g_ray->found_horz_wall)
	? distance_between_points(g_player->x, g_player->y,
		g_ray->wall_horz_hit_x, g_ray->wall_horz_hit_y)
	: INT_MAXX;
	vertical_wall_hint(s_id);
	g_ray->vert_hit_distance = (g_ray->found_vert_wall)
	? distance_between_points(g_player->x, g_player->y,
		g_ray->wall_vert_hit_x, g_ray->wall_vert_hit_y)
	: INT_MAXX;
	calculating_x_y(s_id);
}
