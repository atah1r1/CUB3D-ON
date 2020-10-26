/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 09:07:34 by atahiri           #+#    #+#             */
/*   Updated: 2020/10/26 13:26:13 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    initialize_player()
{
    
    g_player->x = WINDOW_WIDTH / 2;
    g_player->y = WINDOW_HEIGHT / 2;
    g_player->turn_d = 0;
    g_player->walk_d = 0;
    g_player->angle = (30 * RAD);
    g_player->turn_spd = 1 * RAD;
    g_player->walk_spd = TILE_SIZE / 10;
    
}

void    handling_textures()
{
    int i;

    i = 0;
    // texture[0].path = "./0.xpm";
    // texture[1].path = "./1.xpm";
    // texture[2].path = "./2.xpm";
    // texture[3].path = "./3.xpm";
    while (i <= 4)
    {
        texture[i].img = mlx_xpm_file_to_image(g_data->ptr, texture[i].path, &texture[i].width, &texture[i].height);
        texture[i].color = (int*)mlx_get_data_addr(texture[i].img, &g_data->bits_per_pixel, &g_data->size_line, &g_data->endian);
        i++;
    }
}

int		main(int argc, char **argv)
{
	// if (argc != 2)
        // {
        // 	write(1, "Error in arguments...", 22);
        // 	return (0);
        // }
        // if (handle_argv(argv[1]) == 2)
        // {
        // 	write(1, "Invalid / not found Map File ...", 32);
        // 	return(0);
        // }
        //handle(argv[1], &data.parse, &data);
        //ft_init(&data);

        
    if (!(g_data = ((t_struct*)malloc(sizeof(t_struct)))))
        return (0);
    if (!(g_player = (t_player*)malloc(sizeof(t_player))))
        return (0);

    if (argc != 2)
        return (ERROR);
    ft_read(argv[1]);
    //write(1,cc1, 8);
    // printf("R %i %i\n", g_data->w_width, g_data->w_height);
    // printf("F r:%i g:%i b:%i\n", g_data->floor.r, g_data->floor.g, g_data->floor.b);
    // printf("C r:%i g:%i b:%i\n", g_data->ceil.r, g_data->ceil.g, g_data->ceil.b);
    // printf("NO = %s\n", texture[0].path);
    // printf("SO = %s\n", texture[1].path);
    // printf("WE = %s\n", texture[2].path);
    // printf("EA = %s\n", texture[3].path);
    //printf("S = %s\n", texture[4].path);
    //printf("==== %i\n", g_data->map_height);
    // int i = 0;
    // while (g_data->map_height > i)
    // {
    //     //printf("LEN ========= %d", g_data->map[i].len);
    //     printf("%c\n", g_data->map[i].row[1]);
    //     i++;
    // }
    initialize_player();
    g_data->ptr = mlx_init();
    g_data->win = mlx_new_window(g_data->ptr, g_data->w_width, g_data->w_height, "Cub3d By atah1r1");
    //g_data->win = mlx_new_window(g_data->ptr, g_data->w_width, g_data->w_height, "Cub3d By atah1r1"); // map_2d
    handling_textures();
    // if(!(g_data->image = mlx_new_image(g_data->ptr, 1600, 900)))
    //     return (0);
    g_data->image3d = mlx_new_image(g_data->ptr, g_data->w_width, g_data->w_height);
    // if (!(g_data->matrix = (int*)mlx_get_data_addr(g_data->image, &g_data->bits_per_pixel, &g_data->size_line, &g_data->endian)))
    //     return (0);
    g_data->matrix3d = (int*)mlx_get_data_addr(g_data->image3d, &g_data->bits_per_pixel, &g_data->size_line, &g_data->endian);
    mlx_hook(g_data->win, 2, 0, keypress, g_player);
    mlx_hook(g_data->win, 3, 0, keyrelease, g_data);
    mlx_loop_hook(g_data->ptr, loop, g_data);
    mlx_loop(g_data->ptr);
	return (0);
}