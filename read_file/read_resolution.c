/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_resolution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:04:59 by atahiri           #+#    #+#             */
/*   Updated: 2020/12/10 12:27:55 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_chr(char *s, char c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int		resolution_error(char *s)
{
	size_t	i;
	char	*chr;

	i = 0;
	chr = "abcdefghijklmnopqrstuvwxyz,./;'][=-";
	while (i < ft_strlen(chr))
	{
		if (check_chr(s, chr[i]) == ERROR)
			set_error("Resolution must be a digit !");
		i++;
	}
	return (SUCCESS);
}

int		read_resolution(char *line)
{
	size_t		i;
	char		**parts;

	i = 0;
	parts = ft_split(line, ' ');
	if (parts_number(parts) != 3)
		return (ERROR);
	resolution_error(parts[1]);
	resolution_error(parts[2]);
	g_data->w_width = ft_atoi(parts[1]);
	g_data->w_height = ft_atoi(parts[2]);
	if (g_data->w_width <= 0)
		set_error("Width must be greather than 0");
	if (g_data->w_height <= 0)
		set_error("height must be greather than 0");
	if (g_data->w_width > 3200 || g_data->w_height > 1800)
	{
		g_data->w_width = 2560;
		g_data->w_height = 1440;
	}
	// ++g_read_nb;
	free(line);
	return (parts_free(parts));
}
