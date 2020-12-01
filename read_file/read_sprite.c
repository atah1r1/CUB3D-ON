/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 10:16:03 by atahiri           #+#    #+#             */
/*   Updated: 2020/11/30 17:15:44 by atahiri          ###   ########.fr       */
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

void	sprite_pos(void)
{
	int i;
	int j;

	i = 0;
	while (g_data->map_height > i)
	{
		j = 0;
		while (j < g_data->map[i].len)
		{
			if (g_data->map[i].row[j] == '2')
			{
				g_sprite[g_sindex].x = (j + 0.5F) * TILE_SIZE;
				g_sprite[g_sindex].y = (i + 0.5F) * TILE_SIZE;
				g_sindex++;
			}
			j++;
		}
		i++;
	}
}
