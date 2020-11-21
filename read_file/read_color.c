/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:50:25 by atahiri           #+#    #+#             */
/*   Updated: 2020/11/21 16:55:51 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		read_color(char *line, t_color *color)
{
	int		i;
	char	**parts;

	i = 0;
	while (!(line[i] >= '0' && line[i] <= '9'))
		i++;
	parts = ft_split(&line[i], ',');
	if (parts_number(parts) != 3)
		return (ERROR);
	color->r = ft_atoi(parts[0]);
	color->g = ft_atoi(parts[1]);
	color->b = ft_atoi(parts[2]);
	++g_read_nb;
	free(line);
	return (parts_free(parts));
}
