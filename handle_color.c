/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:01:47 by atahiri           #+#    #+#             */
/*   Updated: 2020/10/25 10:43:13 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int    handle_color(t_color *color)
{
    int result;
    result = color->r * 256 * 256;
    result = result + color->g * 256;
    result = result + color->b;
    return result;
}
