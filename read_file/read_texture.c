/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:03:44 by atahiri           #+#    #+#             */
/*   Updated: 2020/12/07 14:25:58 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		r_txt(char *line, t_texture *txt)
{
	int		i;
	char	**parts;

	i = 0;
	parts = ft_split(line, ' ');
	if (parts_number(parts) != 2)
		return (ERROR);
	txt->path = ft_strdup(parts[1]);
	// ++g_read_nb;
	free(line);
	return (parts_free(parts));
}
