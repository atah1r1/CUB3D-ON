/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:09:45 by atahiri           #+#    #+#             */
/*   Updated: 2020/11/30 11:39:24 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	normalize_sprite(float angle)
{
	while (angle - g_player->angle > M_PI)
		angle -= 2 * M_PI;
	while (angle - g_player->angle < -M_PI)
		angle += 2 * M_PI;
	return (angle);
}
