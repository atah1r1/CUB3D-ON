/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 11:35:03 by atahiri           #+#    #+#             */
/*   Updated: 2020/12/07 12:25:17 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		set_error(char *message)
{
	write(1, "Error\n", 6);
	write(1, message, ft_strlen(message));
	exit(SUCCESS);
}
