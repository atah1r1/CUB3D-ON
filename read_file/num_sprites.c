/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 10:16:03 by atahiri           #+#    #+#             */
/*   Updated: 2020/11/27 14:34:21 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		num_sprites(char *line)
{
	size_t	x;

	x = 0;
	while (x < ft_strlen(line))
	{
		if (line[x] == '2')
			g_num_sprites++;
		x++;
	}
	return (0);
}

void	sprite_pos()
{

	int i = 0;
	int j;
	while (g_data->map_height > i)
	{
		j = 0;
		while (j < g_data->map[i].len)
    	{
			if (g_data->map[i].row[j] == '2')
			{
				g_sprite[g_sindex].x = (i + 0.5F) * S_TILE_SIZE;
				g_sprite[g_sindex].y = (j + 0.5F) * S_TILE_SIZE;
				g_sindex++;
			}
			j++;
		}
		i++;
	}
}