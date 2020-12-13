/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:19:49 by atahiri           #+#    #+#             */
/*   Updated: 2020/12/07 18:57:45 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(void)
{
	float nx;
	float ny;

	g_player->angle += (g_player->turn_d * g_player->turn_spd);
	g_player->angle = normalize_angle(g_player->angle);
	nx = g_player->x + cosf(g_player->angle + g_player->side) *
		(g_player->walk_d * g_player->walk_spd);
	ny = g_player->y + sinf(g_player->angle + g_player->side) *
		(g_player->walk_d * g_player->walk_spd);
	if (!(wall_check(nx, ny)) && !(sprite_check(nx, ny)))
	{
		g_player->y = ny;
		g_player->x = nx;
	}
}
