/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 23:27:50 by atahiri           #+#    #+#             */
/*   Updated: 2020/11/23 14:24:32 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_indices(int map_x, int map_y)
{
	if (map_y >= g_data->map_height || map_y < 0)
		return (0);
	if (map_x >= g_data->map[map_y].len || map_x < 0)
		return (0);
	return (1);
}

int		wall_check(float x, float y)
{
	int map_x;
	int map_y;

	map_x = x / TILE_SIZE;
	map_y = y / TILE_SIZE;
	if (!(check_indices(map_x, map_y)))
		return (1);
	if ((int)y < 0 || (map_y > g_data->map_height))
		return (1);
	if (g_data->map[map_y].row[map_x] == '1' ||
		g_data->map[map_y].row[map_x] == '2')
		return (1);
	return (0);
}
