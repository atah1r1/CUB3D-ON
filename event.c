/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 23:17:59 by atahiri           #+#    #+#             */
/*   Updated: 2020/11/24 10:25:44 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		keypress(int keycode)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == FORWARD)
		g_player->walk_d = 1;
	else if (keycode == BACKWARD)
		g_player->walk_d = -1;
	if (keycode == R_RIGHT)
		g_player->turn_d = 1;
	else if (keycode == R_LEFT)
		g_player->turn_d = -1;
	else if (keycode == LEFT)
	{
		g_player->side = -(M_PI / 2);
		g_player->walk_d = 1;
	}
	else if (keycode == RIGHT)
	{
		g_player->side = M_PI / 2;
		g_player->walk_d = 1;
	}
	return (0);
}

int		keyrelease(int keycode)
{
	if (keycode == FORWARD)
		g_player->walk_d = 0;
	if (keycode == BACKWARD)
		g_player->walk_d = 0;
	if (keycode == R_RIGHT)
		g_player->turn_d = 0;
	if (keycode == R_LEFT)
		g_player->turn_d = 0;
	if (keycode == LEFT || keycode == RIGHT)
	{
		g_player->side = 0;
		g_player->walk_d = 0;
	}
	return (0);
}
