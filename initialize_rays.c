/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_rays.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:12:53 by atahiri           #+#    #+#             */
/*   Updated: 2020/11/23 11:13:31 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    initialize_rays(void)
{
    g_ray->found_horz_wall = 0;
    g_ray->wall_horz_hit_x = 0;
    g_ray->wall_horz_hit_y = 0;
    g_ray->found_vert_wall = 0;
    g_ray->wall_vert_hit_x = 0;
    g_ray->wall_vert_hit_y = 0;
}