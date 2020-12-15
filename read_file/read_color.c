/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:50:25 by atahiri           #+#    #+#             */
/*   Updated: 2020/12/10 12:28:28 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_character(char *s, char c)
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

int		color_error(char *s)
{
	size_t	i;
	char	*chr;

	i = 0;
	chr = "abcdefghijklmnopqrstuvwxyz,./;'][=-";
	while (i < ft_strlen(chr))
	{
		if (check_character(s, chr[i]) == ERROR)
			set_error("Colors must be a digit !");
		i++;
	}
	return (SUCCESS);
}

int		ft_find_comma(char *line)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (line[i])
	{
		if (line[i] == ',')
			nb++;
		i++;
	}
	return (nb);
}

int		read_color(char *line, t_color *color)
{
	int		i;
	char	**parts;

	i = 2;
	while (line[i] == ' ')
		i++;
	if (ft_find_comma(line) > 2)
		set_error("Error in Colors");
	parts = ft_split(&line[i], ',');
	if (parts_number(parts) != 3)
		return (ERROR);
	color_error(parts[0]);
	color_error(parts[1]);
	color_error(parts[2]);
	color->r = ft_atoi(parts[0]);
	color->g = ft_atoi(parts[1]);
	color->b = ft_atoi(parts[2]);
	if ((color->r < 0 || color->r > 255) ||
		(color->g < 0 || color->g > 255) || (color->b < 0 || color->b > 255))
		set_error("RGB must be in range[0-255]");
	free(line);
	return (parts_free(parts));
}
