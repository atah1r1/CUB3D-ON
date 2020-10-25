/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 23:17:59 by atahiri           #+#    #+#             */
/*   Updated: 2020/03/09 18:52:24 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		keypress(int keycode)
{
	if (keycode == FORWARD)
		g_player->walk_d = 1;
	else if (keycode == BACKWARD)
		g_player->walk_d = -1;
	if (keycode == RIGHT)
		g_player->turn_d = 1;
	else if (keycode == LEFT)
		g_player->turn_d = -1;
	return (0);
}

int		keyrelease(int keycode)
{
	if (keycode == FORWARD)
		g_player->walk_d = 0;
	if (keycode == BACKWARD)
		g_player->walk_d = 0;
	if (keycode == RIGHT)
		g_player->turn_d = 0;
	if (keycode == LEFT)
		g_player->turn_d = 0;
	return (0);
}
