/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:10:29 by atahiri           #+#    #+#             */
/*   Updated: 2020/11/30 14:59:55 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	color_converter(int hex_value)
{
	if (!(g_bmp_rgb = malloc(sizeof(t_bmp_rgb))))
		set_error("failed to alloc the RGB colors !!");
	g_bmp_rgb->r = (hex_value / pow(2, 16));
	g_bmp_rgb->g = (hex_value / pow(2, 8));
	g_bmp_rgb->b = (hex_value);
}

void	screen_data(int x)
{
	int index;

	index = g_bitmap.row * g_data->w_width + g_bitmap.col;
	index = index < 0 ? index * (-1) : index;
	color_converter((uint32_t)g_data->matrix3d[index]);
	g_bitmap.buf[x * g_bitmap.width_in_pxl
		+ g_bitmap.col * 3 + 0] = g_bmp_rgb->b;
	g_bitmap.buf[x * g_bitmap.width_in_pxl
		+ g_bitmap.col * 3 + 1] = g_bmp_rgb->g;
	g_bitmap.buf[x * g_bitmap.width_in_pxl
		+ g_bitmap.col * 3 + 2] = g_bmp_rgb->r;
	free(g_bmp_rgb);
}

void	screen_init(unsigned char *header)
{
	g_bitmap.bit_per_pxl = 24;
	g_bitmap.width_in_pxl = ((g_data->w_width *
				g_bitmap.bit_per_pxl + 31) / 32) * 4;
	g_bitmap.image_size = g_bitmap.width_in_pxl * g_data->w_height;
	g_bitmap.info_header_size = 40;
	g_bitmap.bf_off_bits = 54;
	g_bitmap.file_size = 54 + g_bitmap.image_size;
	g_bitmap.biplanes = 1;
	ft_memcpy(header, "BM", 2);
	ft_memcpy(header + 2, &(g_bitmap.file_size), 4);
	ft_memcpy(header + 10, &(g_bitmap.bf_off_bits), 4);
	ft_memcpy(header + 14, &(g_bitmap.info_header_size), 4);
	ft_memcpy(header + 18, &(g_data->w_width), 4);
	ft_memcpy(header + 22, &(g_data->w_height), 4);
	ft_memcpy(header + 26, &(g_bitmap.biplanes), 2);
	ft_memcpy(header + 28, &(g_bitmap.bit_per_pxl), 2);
}

int		bmp_file(void)
{
	int				x;
	const char		*file_name = "screenshot.bmp";
	const int		len = 54;
	unsigned char	header[len];

	ft_memset(header, 0, len);
	screen_init(header);
	if (!(g_bitmap.buf = malloc((g_bitmap.image_size))))
		set_error("failed to alloc the bitmap buffer !!");
	x = 0;
	g_bitmap.row = g_data->w_height - 1;
	while (g_bitmap.row-- >= 0)
	{
		g_bitmap.col = 0;
		while (g_bitmap.col++ < g_data->w_width)
			screen_data(x);
		x++;
	}
	g_bitmap.fd = open(file_name, O_WRONLY | O_CREAT);
	write(g_bitmap.fd, header, len);
	write(g_bitmap.fd, g_bitmap.buf, g_bitmap.image_size);
	close(g_bitmap.fd);
	free(g_bitmap.buf);
	return (0);
}