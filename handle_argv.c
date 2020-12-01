/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_argv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:11:24 by atahiri           #+#    #+#             */
/*   Updated: 2020/12/01 11:55:54 by atahiri          ###   ########.fr       */
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

int		handle_save_arg(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (ft_strncmp(str, "--save", len))
		return (ERROR);
	return (SUCCESS);
}
