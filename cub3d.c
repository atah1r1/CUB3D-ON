/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 09:07:34 by atahiri           #+#    #+#             */
/*   Updated: 2020/11/22 17:27:02 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_player(void)
{
	g_player->turn_d = 0;
	g_player->walk_d = 0;
	g_player->turn_spd = 1 * RAD;
	g_player->walk_spd = TILE_SIZE / 10;
}

void	handling_textures(void)
{
	int i;

	i = 0;
	while (i <= 4)
	{
		g_texture[i].img = mlx_xpm_file_to_image(g_data->ptr, g_texture[i].path,
			&g_texture[i].width, &g_texture[i].height);
		g_texture[i].color = (int*)mlx_get_data_addr(g_texture[i].img,
			&g_data->bits_per_pixel, &g_data->size_line, &g_data->endian);
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "Error in arguments...", 22);
		return (0);
	}
	if (!(g_data = ((t_struct*)malloc(sizeof(t_struct)))))
		return (0);
	if (!(g_player = (t_player*)malloc(sizeof(t_player))))
		return (0);
	if (!(g_data->sprite = (t_sprite*)malloc(sizeof(t_sprite))))
		return (0);
	ft_read(argv[1]);
	initialize_player();
	g_data->ptr = mlx_init();
	g_data->win = mlx_new_window(g_data->ptr, g_data->w_width,
				g_data->w_height, "Cub3d");
	handling_textures();
	g_data->image3d = mlx_new_image(g_data->ptr, g_data->w_width,
				g_data->w_height);
	g_data->matrix3d = (int*)mlx_get_data_addr(g_data->image3d,
				&g_data->bits_per_pixel, &g_data->size_line, &g_data->endian);
	mlx_hook(g_data->win, 2, 0, keypress, g_player);
	mlx_hook(g_data->win, 3, 0, keyrelease, g_data);
	mlx_loop_hook(g_data->ptr, loop, g_data);
	mlx_loop(g_data->ptr);
	free(&g_read_nb);
	return (0);
}
