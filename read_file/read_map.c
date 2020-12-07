/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:46:14 by atahiri           #+#    #+#             */
/*   Updated: 2020/12/07 11:47:43 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		init_map(char *line)
{
	if (!(g_data->map = malloc(1 * sizeof(t_map))))
		return (ERROR);
	g_data->map[0].row = ft_strdup(line);
	g_data->map[0].len = ft_strlen(line);
	g_data->map_height = 1;
	g_data->map->num_columns = 0;
	free(line);
	return (SUCCESS);
}

int		read_map_row(char *line)
{
	int		i;
	t_map	*temp_map;

	i = 0;
	if (g_read_nb != 8)
		return (ERROR);
	if (g_data->map == NULL)
		return (init_map(line));
	temp_map = g_data->map;
	if (!(g_data->map = (t_map *)malloc(sizeof(t_map) *
		(++g_data->map_height))))
		return (ERROR);
	while (g_data->map_height - 1 > i)
	{
		g_data->map[i] = temp_map[i];
		i++;
	}
	g_data->map[i].row = ft_strdup(line);
	g_data->map[i].len = ft_strlen(line);
	if (player_pos(line, i) > 1)
		set_error("Too many player in the map !");
	g_data->map->num_columns = (g_data->map->num_columns > g_data->map[i].len)
	? g_data->map->num_columns : g_data->map[i].len;
	num_sprites(line);
	free(line);
	free(temp_map);
	return (SUCCESS);
}
