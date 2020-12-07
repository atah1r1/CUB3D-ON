/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_resolution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:04:59 by atahiri           #+#    #+#             */
/*   Updated: 2020/12/07 12:00:31 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		read_resolution(char *line)
{
	int		i;
	char	**parts;

	i = 0;
	parts = ft_split(line, ' ');
	if (parts_number(parts) != 3)
		return (ERROR);
	g_data->w_width = atoi(parts[1]);
	g_data->w_height = atoi(parts[2]);
	if (g_data->w_width > 3200 || g_data->w_height > 1800)
	{
		g_data->w_width = 3200;
		g_data->w_height = 1800;
	}
	if (g_data->w_width <= 0 || g_data->w_height <= 0)
		set_error("Width and height must be greather than 0");
	++g_read_nb;
	free(line);
	return (parts_free(parts));
}
