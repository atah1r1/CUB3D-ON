/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:04:20 by atahiri           #+#    #+#             */
/*   Updated: 2020/12/01 12:04:34 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		handling_textures(void)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (!(g_texture[i].img = mlx_xpm_file_to_image(g_data->ptr,
			g_texture[i].path,
			&g_texture[i].width, &g_texture[i].height)))
			set_error("Invalid/Missing xpm file !");
		g_texture[i].color = (int*)mlx_get_data_addr(g_texture[i].img,
			&g_data->bits_per_pixel, &g_data->size_line, &g_data->endian);
		i++;
	}
	return (0);
}
