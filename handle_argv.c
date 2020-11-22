/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_argv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:11:24 by atahiri           #+#    #+#             */
/*   Updated: 2020/11/22 12:27:39 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

int		handle_argv(char *str)
{
	int len;

	len = ft_strlen(str);
	if (ft_strncmp(str + (len - 4), ".cub", 4))
		return (ERROR);
	return (SUCCESS);
}
