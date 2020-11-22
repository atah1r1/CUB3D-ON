/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:02:51 by atahiri           #+#    #+#             */
/*   Updated: 2020/11/22 12:26:48 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' ||
			str[i] == '\t' ||
			str[i] == '\n' ||
			str[i] == '\v' ||
			str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}
