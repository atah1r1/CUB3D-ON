/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 09:07:34 by atahiri           #+#    #+#             */
/*   Updated: 2020/11/29 18:51:22 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_player(void)
{
	g_player->turn_d = 0;
	g_player->walk_d = 0;
	g_player->turn_spd = 1 * RAD;
	g_player->walk_spd = TILE_SIZE / 10;
	g_player->side = 0;
}

int		exit_event(void)
{
	exit(0);
	return (0);
}

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

int		main(int argc, char **argv)
{
	g_sindex = 0;
	if (argc != 2)
		set_error("Error in arguments...");
	if (!(g_data = ((t_struct*)malloc(sizeof(t_struct)))))
		return (0);
	if (!(g_player = (t_player*)malloc(sizeof(t_player))))
		return (0);
	ft_read(argv[1]);
	if (!(g_sprite = (t_sprite*)malloc(sizeof(t_sprite) * g_num_sprites)))
		return (0);
	sprite_pos();
	// int i = 0;
	// while (i < g_num_sprites)
	// {
	// 	printf("index === %d ||X === %f || Y === %f\n", i, g_sprite[i].x, g_sprite[i].y);
	// 	i++;
	// }
	//printf("%s", g_texture[4].path);
	initialize_player();
	g_data->ptr = mlx_init();
	handling_textures();
	g_data->win = mlx_new_window(g_data->ptr, g_data->w_width,
				g_data->w_height, "Cub3d");
	g_data->image3d = mlx_new_image(g_data->ptr, g_data->w_width,
				g_data->w_height);
	g_data->matrix3d = (int*)mlx_get_data_addr(g_data->image3d,
				&g_data->bits_per_pixel, &g_data->size_line, &g_data->endian);
	mlx_hook(g_data->win, 2, 0, keypress, g_player);
	mlx_hook(g_data->win, 3, 0, keyrelease, g_player);
	mlx_hook(g_data->win, 17, 1L << 17, exit_event, g_data);
	mlx_loop_hook(g_data->ptr, loop, g_data);
	mlx_loop(g_data->ptr);
	return (0);
}
