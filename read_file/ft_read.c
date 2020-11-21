/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:31:58 by atahiri           #+#    #+#             */
/*   Updated: 2020/11/21 16:44:34 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		read_line(char *line)
{
	if (ft_strncmp(line, "R ", 2) == 0 && read_resolution(line) == ERROR)
		return (set_error("res error!"));
	else if (ft_strncmp(line, "NO", 2) == 0
		&& read_texture(line, &g_texture[0]) == ERROR)
		return (set_error("no error!"));
	else if (ft_strncmp(line, "SO", 2) == 0
		&& read_texture(line, &g_texture[1]) == ERROR)
		return (set_error("no error!"));
	else if (ft_strncmp(line, "WE", 2) == 0
		&& read_texture(line, &g_texture[3]) == ERROR)
		return (set_error("no error!"));
	else if (ft_strncmp(line, "EA", 2) == 0
		&& read_texture(line, &g_texture[2]) == ERROR)
		return (set_error("no error!"));
	else if (ft_strncmp(line, "S ", 2) == 0
		&& read_texture(line, &g_texture[4]) == ERROR)
		return (set_error("s error!"));
	else if (ft_strncmp(line, "F ", 2) == 0
		&& read_color(line, &(g_data->floor)) == ERROR)
		return (set_error("f error"));
	else if (ft_strncmp(line, "C ", 2) == 0
		&& read_color(line, &(g_data->ceil)) == ERROR)
		return (set_error("c error"));
	else if ((line[0] == '1' || line[0] == ' ') && read_map_row(line) == ERROR)
		return (set_error("map error"));
	return (SUCCESS);
}

int		ft_read(char *file_name)
{
	int		fd;
	char	*line;

	g_read_nb = 0;
	g_data->map_height = 0;
	if (handle_argv(file_name) == ERROR)
		return (set_error("error"));
	if ((fd = open(file_name, O_RDONLY)) < 0)
		return (set_error("error 2"));
	while (get_next_line(fd, &line) > 0)
		if (read_line(line) == ERROR)
			return (ERROR);
	if (read_line(line) == ERROR)
		return (ERROR);
	close(fd);
	return (SUCCESS);
}
