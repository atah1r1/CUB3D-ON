/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 09:36:16 by atahiri           #+#    #+#             */
/*   Updated: 2020/10/19 11:10:04 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     handle_argv(char *str)
{
    int len;
    
    len = ft_strlen(str);
    if (ft_strncmp(str + (len - 4), ".cub", 4))
        return (ERROR);
    return (SUCCESS);
}