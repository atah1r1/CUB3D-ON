/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:46:14 by atahiri           #+#    #+#             */
/*   Updated: 2020/11/26 12:24:56 by atahiri          ###   ########.fr       */
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
	free(line);
	return (SUCCESS);
}

int		read_map_row(char *line)
{
	int		i;
	t_map	*temp_map;

	i = 0;
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
	if (player_pos(line, i) > 1)
		set_error("Too many player in the map !");
	if (g_player_found == 0)
		set_error("Player not found");
	//sprite_handle(line, i);
	g_data->map[i].row = ft_strdup(line);
	g_data->map[i].len = ft_strlen(line);
	free(line);
	free(temp_map); //++ to remove leaks
	return (SUCCESS);
}
