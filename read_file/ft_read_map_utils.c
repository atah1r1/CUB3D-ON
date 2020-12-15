/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 11:46:59 by atahiri           #+#    #+#             */
/*   Updated: 2020/12/07 11:52:36 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		valid_indices(t_struct *data, int x, int y)
{
	if (y >= data->map_height || y < 0)
		return (SUCCESS);
	if (x >= g_data->map[y].len || x < 0)
		return (SUCCESS);
	return (ERROR);
}

int		value_at(int i, int j, t_struct *data)
{
	if (valid_indices(data, j, i))
		return (data->map[i].row[j]);
	return (' ');
}

int		check_element(t_struct *data, int i, int j)
{
	int x;
	int z;

	x = -1;
	while (x <= 1)
	{
		z = -1;
		while (z <= 1)
		{
			if (value_at(i + x, j + z, data) == ' ')
				return (SUCCESS);
			z++;
		}
		x++;
	}
	return (ERROR);
}

void	check_map_opened(t_struct *data)
{
	int i;
	int j;

	i = -1;
	while (++i < data->map_height)
	{
		j = -1;
		while (++j < g_data->map[i].len)
		{
			if (!(data->map[i].row[j] == '1' || data->map[i].row[j] == ' ')
					&& !check_element(data, i, j))
				set_error("Map Opened !!");
		}
	}
}
