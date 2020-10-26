/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:01:47 by atahiri           #+#    #+#             */
/*   Updated: 2020/10/26 10:35:48 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int    handle_color(t_color *color)
{
    //int result;
    //result = (color->r * 256 * 256) + (color->g * 256) + color->b;
    return ((color->r * 256 * 256) + (color->g * 256) + color->b);
}
