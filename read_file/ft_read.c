/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:31:58 by atahiri           #+#    #+#             */
/*   Updated: 2020/12/01 17:01:00 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		read_line(char *line)
{
	if (ft_strncmp(line, "R ", 2) == 0 && read_resolution(line) == ERROR)
		return (set_error("resolution error!"));
	else if (ft_strncmp(line, "NO", 2) == 0
		&& read_texture(line, &g_texture[0]) == ERROR)
		return (set_error("NORTH error!"));
	else if (ft_strncmp(line, "SO", 2) == 0
		&& read_texture(line, &g_texture[1]) == ERROR)
		return (set_error("SOUTH error!"));
	else if (ft_strncmp(line, "WE", 2) == 0
		&& read_texture(line, &g_texture[3]) == ERROR)
		return (set_error("WEST error!"));
	else if (ft_strncmp(line, "EA", 2) == 0
		&& read_texture(line, &g_texture[2]) == ERROR)
		return (set_error("EAST error!"));
	else if (ft_strncmp(line, "S ", 2) == 0
		&& read_texture(line, &g_texture[4]) == ERROR)
		return (set_error("SPRITE error!"));
	else if (ft_strncmp(line, "F ", 2) == 0
		&& read_color(line, &(g_data->floor)) == ERROR)
		return (set_error("FLOOR RGB error!"));
	else if (ft_strncmp(line, "C ", 2) == 0
		&& read_color(line, &(g_data->ceil)) == ERROR)
		return (set_error("CIEL RGB error!"));
	else if (((line[0] == '1' || line[0] == ' ')
		&& read_map_row(line) == ERROR))
		return (set_error("map error!"));
	return (SUCCESS);
}

int		ft_read(char *file_name)
{
	int		fd;
	char	*line;

	g_read_nb = 0;
	if (handle_argv(file_name) == ERROR)
		return (set_error("file doesn't have a correct format"));
	if ((fd = open(file_name, O_RDONLY)) < 0)
		return (set_error(".cub file doesn't exist"));
	while (get_next_line(fd, &line) > 0)
		if (read_line(line) == ERROR)
			return (ERROR);
	if (read_line(line) == ERROR)
		return (ERROR);
	if (g_player->player_found == 0)
		set_error("Player not found");
	close(fd);
	return (SUCCESS);
}
