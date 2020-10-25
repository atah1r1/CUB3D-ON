/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 09:07:34 by atahiri           #+#    #+#             */
/*   Updated: 2020/10/23 16:51:04 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     g_read_nb;



int     parts_number(char **parts)
{
    int  i = 0;
    while (parts[i] != NULL)
        ++i;
    return (i);
}

int     parts_free(char **parts)
{
    int i = 0;
    while (parts[i] != NULL)
        free(parts[i++]);
    free(parts);
    return (SUCCESS);
}

int     read_resolution(char *line)
{
    int i;

    i = 0;
    char **parts = ft_split(line, ' ');
    if (parts_number(parts) != 3)
        return (ERROR);
    g_data->w_width = atoi(parts[1]);
    g_data->w_height = atoi(parts[2]);
    ++g_read_nb;
    free(line);
    return (parts_free(parts));
}

int     read_texture(char *line, t_texture *txt)
{
    int i = 0;
    char **parts = ft_split(line, ' ');
    if (parts_number(parts) != 2)
        return (ERROR);
    txt->path = ft_strdup(parts[1]);
    ++g_read_nb;
    free(line);
    return (parts_free(parts));
}

int     read_color(char *line, t_color *color)
{
    int i = 0;
    while (!(line[i] >= '0' && line[i] <= '9'))
        i++;
    char **parts = ft_split(&line[i], ',');
    if (parts_number(parts) != 3)
        return (ERROR);
    color->r = atoi(parts[0]);
    color->g = atoi(parts[1]);
    color->b = atoi(parts[2]);
    ++g_read_nb;
    free(line);
    return (parts_free(parts));
}

int     init_map(char *line)
{
    if (!(g_data->map = malloc(1 * sizeof(t_map))))
        return (ERROR);
    g_data->map[0].row = ft_strdup(line);
    g_data->map[0].len = ft_strlen(line);
    g_data->map_height = 1;
    free(line);
    return (SUCCESS);
}

int     read_map_row(char *line)
{
    int     i = 0; // i = -1
    t_map   *temp_map;

    //printf("> %s\n", line);
    
    if (g_data->map == NULL)
        return (init_map(line));
        
    temp_map = g_data->map;
    if (!(g_data->map = (t_map *)malloc(sizeof(t_map) * (++g_data->map_height))))
        return (ERROR);

    while (g_data->map_height - 1 > i)
    {
        g_data->map[i] = temp_map[i];
        i++;
    }
    g_data->map[i].row = ft_strdup(line);
    g_data->map[i].len = ft_strlen(line);
    free(line);
    return (SUCCESS);
    // if (g_read_nb != 8)
    //     return (ERROR);
    // temp_map = g_data->map;
    // if (!(g_data->map = (t_map *)malloc(sizeof(t_map) * (++g_data->map_height))))
    //     return (ERROR);
    // if (temp_map != NULL)
    // {
    //     while (++i < g_data->map_height - 1)
    //     {
    //         g_data->map[i].row = temp_map[i].row;
    //         g_data->map[i].len = temp_map[i].len;
    //     }
    // }
    // g_data->map[i].row = ft_strdup(line);
    // g_data->map[i].len = ft_strlen(line);
    // if (temp_map != NULL)
    //     free(temp_map);
    // //free(line);
    // return (SUCCESS);
}

int     read_line(char *line)
{
    if (ft_strncmp(line, "R ", 2) == 0 
        && read_resolution(line) == ERROR)
        return (set_error("res error!"));
    else if (ft_strncmp(line, "NO", 2) == 0
        && read_texture(line, &texture[0]) == ERROR)
        return (set_error("no error!"));
    else if (ft_strncmp(line, "SO", 2) == 0
        && read_texture(line, &texture[1]) == ERROR)
        return (set_error("no error!"));
    else if (ft_strncmp(line, "WE", 2) == 0
        && read_texture(line, &texture[3]) == ERROR)
        return (set_error("no error!"));
    else if (ft_strncmp(line, "EA", 2) == 0
        && read_texture(line, &texture[2]) == ERROR)
        return (set_error("no error!"));
    else if (ft_strncmp(line, "S ", 2) == 0
        && read_texture(line, &texture[4]) == ERROR)
        return (set_error("s error!"));
    else if (ft_strncmp(line, "F ", 2) == 0
        && read_color(line, &(g_data->floor)) == ERROR)
        return (set_error("f error"));
    else if (ft_strncmp(line, "C ", 2) == 0
        && read_color(line, &(g_data->ceil)) == ERROR)
        return (set_error("c error"));
    else if ((line[0] == '1' || line[0] == ' ')
        && read_map_row(line) == ERROR)
        return (set_error("map error"));
    return (SUCCESS);
}

int     ft_read(char *file_name)
{
    int fd;
    char *line;
    
    g_read_nb = 0;
    g_data->map_height = 0;
    if (handle_argv(file_name) == ERROR)
        return set_error("error");
    if ((fd = open(file_name, O_RDONLY)) < 0)
        return set_error("error 2");
    while (get_next_line(fd, &line) > 0)
        if (read_line(line) == ERROR)
            return (ERROR);
    if (read_line(line) == ERROR)
        return (ERROR);
    close(fd);
    return (SUCCESS);
}