/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:18:55 by atahiri           #+#    #+#             */
/*   Updated: 2020/10/26 11:19:21 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    handle_rays(int strip_id)
{
    
    g_ray[strip_id].ray_angle = normalize_angle(g_ray[strip_id].ray_angle);
    g_ray[strip_id].wall_facing_down = g_ray[strip_id].ray_angle > 0 && g_ray[strip_id].ray_angle < M_PI;
    g_ray[strip_id].wall_facing_up = !g_ray[strip_id].wall_facing_down;
    g_ray[strip_id].wall_facing_right = g_ray[strip_id].ray_angle < 0.5 * M_PI || g_ray[strip_id].ray_angle > 1.5 * M_PI;
    g_ray[strip_id].wall_facing_left = !g_ray[strip_id].wall_facing_right;
    float x_intercept;
    float y_intercept;
    float xstep;
    float ystep;

    g_ray[strip_id].hit_ver = 0;
/////////////////////////////////////////////////////////
//// horizontal wall hint find
////////////////////////////////////////////////////////
    float next_horz_x;
    float next_horz_y;
    int found_horz_wall;
    float wall_horz_hit_x;
    float wall_horz_hit_y;
    float horz_hit_distance;

    found_horz_wall = 0;
    wall_horz_hit_x = 0;
    wall_horz_hit_y = 0;

    y_intercept = floor(g_player->y / TILE_SIZE) * TILE_SIZE;
    y_intercept += g_ray[strip_id].wall_facing_down ? TILE_SIZE : 0;
    
    x_intercept = g_player->x + (y_intercept - g_player->y) / tan(g_ray[strip_id].ray_angle);

    ystep = TILE_SIZE;
    ystep *= g_ray[strip_id].wall_facing_up ? -1 : 1;

    xstep = TILE_SIZE / tan(g_ray[strip_id].ray_angle);
    xstep *= (g_ray[strip_id].wall_facing_left && xstep > 0) ? -1 : 1;
    xstep *= (g_ray[strip_id].wall_facing_right && xstep < 0) ? -1 : 1;

    next_horz_x = x_intercept;
    next_horz_y = y_intercept;

    // if (g_ray[strip_id].wall_facing_up)
    //     next_horz_y--;
    while (next_horz_x >= 0 && next_horz_x <= 112 * TILE_SIZE && 
            next_horz_y >= 0 && next_horz_y <= g_data->map_height * TILE_SIZE)
    {
        if (wall_check(next_horz_x, g_ray[strip_id].wall_facing_up ? next_horz_y - 1 : next_horz_y))
        {
            found_horz_wall = 1;
            wall_horz_hit_x = next_horz_x;
            wall_horz_hit_y = next_horz_y;
            break;
        }
        else
        {
            next_horz_x += xstep;
            next_horz_y += ystep;
        }
    }
    ////////////////////////// find distance horizontal //////////////
    horz_hit_distance = (found_horz_wall)
    ? distance_between_points(g_player->x, g_player->y, wall_horz_hit_x, wall_horz_hit_y) 
    : INT_MAXX;
/////////////////////////////////////////////////////////
//// vertical wall hint find
////////////////////////////////////////////////////////
    float   next_vert_x;
    float   next_vert_y;
    int     found_vert_wall;
    float   wall_vert_hit_x;
    float   wall_vert_hit_y;
    float   vert_hit_distance;

    found_vert_wall = 0;
    wall_vert_hit_x = 0;
    wall_vert_hit_y = 0;

    x_intercept = floor(g_player->x / TILE_SIZE) * TILE_SIZE;
    x_intercept += g_ray[strip_id].wall_facing_right ? TILE_SIZE : 0;
    
    y_intercept = g_player->y + (x_intercept - g_player->x) * tan(g_ray[strip_id].ray_angle);

    xstep = TILE_SIZE;
    xstep *= g_ray[strip_id].wall_facing_left ? -1 : 1;

    ystep = TILE_SIZE * tan(g_ray[strip_id].ray_angle);
    ystep *= (g_ray[strip_id].wall_facing_up && ystep > 0) ? -1 : 1;
    ystep *= (g_ray[strip_id].wall_facing_down && ystep < 0) ? -1 : 1;

    next_vert_x = x_intercept;
    next_vert_y = y_intercept;

    // if (g_ray[strip_id].wall_facing_left)
    //     next_vert_x--;
    while (next_vert_x >= 0 && next_vert_x <= 112 * TILE_SIZE && 
            next_vert_y >= 0 && next_vert_y <= g_data->map_height * TILE_SIZE)
    {
        if (wall_check(g_ray[strip_id].wall_facing_left ? next_vert_x - 1 : next_vert_x, next_vert_y))
        {
            found_vert_wall = 1;
            wall_vert_hit_x = next_vert_x;
            wall_vert_hit_y = next_vert_y;
            break;
        }
        else
        {
            next_vert_x += xstep;
            next_vert_y += ystep;
        }
    }
    ////////////////////////// find distance vertical //////////////

    vert_hit_distance = (found_vert_wall)
    ? distance_between_points(g_player->x, g_player->y, wall_vert_hit_x, wall_vert_hit_y) 
    : INT_MAXX;
    
    ///////////////////////////////////////////////////////////////////////////
    g_ray[strip_id].wall_hit_x = (horz_hit_distance < vert_hit_distance) ? wall_horz_hit_x : wall_vert_hit_x;
    g_ray[strip_id].wall_hit_y = (horz_hit_distance < vert_hit_distance) ? wall_horz_hit_y : wall_vert_hit_y;
    g_ray[strip_id].distance = (horz_hit_distance < vert_hit_distance) ? horz_hit_distance : vert_hit_distance;
    g_ray[strip_id].hit_ver = (vert_hit_distance < horz_hit_distance);
}