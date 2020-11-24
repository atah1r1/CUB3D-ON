/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:19:49 by atahiri           #+#    #+#             */
/*   Updated: 2020/11/24 09:50:51 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(void)
{
	float nx;
	float ny;

	g_player->angle += (g_player->turn_d * g_player->turn_spd);
	g_player->angle = normalize_angle(g_player->angle);
	nx = g_player->x + (g_player->walk_d * g_player->walk_spd *
						cosf(g_player->angle + g_player->side));
	ny = g_player->y + (g_player->walk_d * g_player->walk_spd *
						sinf(g_player->angle + g_player->side));
	if (!(wall_check(nx, g_player->y)))
		g_player->x = nx;
	if (!(wall_check(g_player->x, ny)))
		g_player->y = ny;
}
