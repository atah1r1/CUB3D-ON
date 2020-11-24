/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:06:21 by atahiri           #+#    #+#             */
/*   Updated: 2020/11/24 12:28:23 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		parts_number(char **parts)
{
	int	i;

	i = 0;
	while (parts[i] != NULL)
		++i;
	return (i);
}

int		parts_free(char **parts)
{
	int i;

	i = 0;
	while (parts[i] != NULL)
		free(parts[i++]);
	free(parts);
	return (SUCCESS);
}
