/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:30:36 by atahiri           #+#    #+#             */
/*   Updated: 2020/11/25 14:32:55 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		player_pos(char *line, int y)
{
	int x;

	x = 0;
	while (x < strlen(line))
	{
		if (line[x] == 'N' || line[x] == 'S'
			|| line[x] == 'W' || line[x] == 'E')
		{
			g_player->x = (x + 0.5F) * TILE_SIZE;
			g_player->y = (y + 0.5F) * TILE_SIZE;
			if (line[x] == 'N')
				g_player->angle = (270 * RAD);
			else if (line[x] == 'S')
				g_player->angle = (90 * RAD);
			else if (line[x] == 'W')
				g_player->angle = (180 * RAD);
			else if (line[x] == 'E')
				g_player->angle = (0);
			g_player_found++;
		}
		x++;
	}
	return (0);
}
