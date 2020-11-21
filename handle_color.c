/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:01:47 by atahiri           #+#    #+#             */
/*   Updated: 2020/11/21 14:01:04 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int    handle_color(t_color *color)
{
    return ((color->r * 256 * 256) + (color->g * 256) + color->b);
}
