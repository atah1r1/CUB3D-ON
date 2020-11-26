/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 09:09:05 by atahiri           #+#    #+#             */
/*   Updated: 2020/11/25 21:00:19 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libs/minilibx/mlx.h"
# include "gnl/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <stdint.h>

# define ESC 53
# define R_LEFT 123
# define R_RIGHT 124
# define LEFT 0
# define RIGHT 2
# define FORWARD 13
# define BACKWARD 1

# define ERROR 2
# define SUCCESS 0

# define TILE_SIZE 400
# define RAD (M_PI / 180)
# define FOV_ANGLE (60 * RAD)
# define WALL_STRIP_WIDTH 1
# define INT_MAXX 2147483647

typedef struct	s_ray
{
	float		ray_angle;
	float		wall_hit_x;
	float		wall_hit_y;
	float		distance;
	int			hit_ver;
	int			wall_face_up;
	int			wall_face_down;
	int			wall_face_left;
	int			wall_face_right;
	int			wall_hit_content;
	float		x_intercept;
	float		y_intercept;
	float		xstep;
	float		ystep;
	float		next_horz_x;
	float		next_horz_y;
	int			found_horz_wall;
	float		wall_horz_hit_x;
	float		wall_horz_hit_y;
	float		horz_hit_distance;
	float		next_vert_x;
	float		next_vert_y;
	int			found_vert_wall;
	float		wall_vert_hit_x;
	float		wall_vert_hit_y;
	float		vert_hit_distance;
}				t_ray;

typedef	struct	s_player
{
	float		x;
	float		y;
	int			turn_d;
	int			walk_d;
	float		angle;
	float		walk_spd;
	float		turn_spd;
	float		side;
}				t_player;

typedef struct	s_texture
{
	void		*img;
	int			width;
	int			height;
	char		*path;
	int			*color;
}				t_texture;

typedef	struct	s_three_d
{
	float		cor_distance;
	float		dis_proj_pln;
	float		prj_wall_h;
	float		wall_tp_px;
	float		wall_bottom_px;
	float		dist_from_top;
	int			txt_off_y;
	int			txt_off_x;
	int			texelcolor;
}				t_three_d;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_sprite
{
	float		x;
	float		y;
	float		x_off;
	float		y_off;
	float		size;
	float		dist;
}				t_sprite;

typedef	struct	s_map
{
	char		*row;
	int			len;
	int			num_columns;
}				t_map;

typedef struct	s_struct
{
	int			w_width;
	int			w_height;
	void		*ptr;
	void		*win;
	void		*image3d;
	int			*matrix3d;
	int			map_height;
	t_color		ceil;
	t_color		floor;
	t_map		*map;
	t_sprite	*sprite;
	int			bits_per_pixel;
	int			size_line;
	int			endian;

}				t_struct;

t_struct		*g_data;
t_player		*g_player;
t_ray			*g_ray;
t_three_d		g_threed;
t_texture		g_texture[5];
int				g_read_nb;
int				g_player_found;

int				ft_memcmp_zero(const void *s1, const void *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				keyrelease(int keycode);
int				keypress(int keycode);
void			initialize_player();
void			three_d(void);
int				loop();
void			move_player();
int				wall_check(float x, float y);
void			cast_rays(void);
void			handle_rays(int strip_id);
float			distance_between_points(float x1, float y1, float x2, float y2);
float			normalize_angle(float angle);
int				handling_textures();
int				ft_read(char *file_name);
int				set_error(char *message);
int				handle_argv(char *str);
char			**ft_split(const char *ss, char c);
int				handle_color(t_color *color);
int				ft_atoi(const char *str);
int				read_line(char *line);
int				read_color(char *line, t_color *color);
int				init_map(char *line);
int				read_map_row(char *line);
int				read_resolution(char *line);
int				read_texture(char *line, t_texture *txt);
int				parts_number(char **parts);
int				parts_free(char **parts);
int				player_pos(char *line, int y);
void			initialize_rays(void);

#endif
