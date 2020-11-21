/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 23:27:50 by atahiri           #+#    #+#             */
/*   Updated: 2020/11/21 17:26:56 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		wall_check(float x, float y)
{
	int map_x;
	int map_y;

	map_x = x / TILE_SIZE;
	map_y = y / TILE_SIZE;
	if (g_data->map[map_y].row[map_x] == '1' ||
		g_data->map[map_y].row[map_x] == '2')
		return (1);
	return (0);
}
