/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:08:14 by mel-mora          #+#    #+#             */
/*   Updated: 2025/08/09 17:16:42 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

/* ************************************************************************** */
/*                                  MACROS                                    */
/* ************************************************************************** */

# define WIN_W                 1024
# define WIN_H                 768

# define BLOCK                 64
# define DEBUG                 0

/* Keycodes */
# define Z                     6
# define Q                     12
# define W                     13
# define A                     0
# define S                     1
# define D                     2
# define ESC                   53
# define LEFT                  123
# define RIGHT                 124

# define PI                    3.14159265359

/* Movement / timing */
# define BASE_MOVE_STEP        2.5
# define BASE_ROT_STEP         1.5
# define DOOR_OPEN_SPEED       1.5f
# define DOOR_OPEN_TIME        3.0f

/* Minimap */
# define MINIMAP_SIZE          192
# define MINIMAP_OFFSET_X      20
# define MINIMAP_OFFSET_Y      20
# define TILE_SIZE             14
# define PLAYER_SIZE           6

/* Colors */
# define COLOR_WALL            0xCCCCCC
# define COLOR_DOOR            0x964B00
# define COLOR_FLOOR           0x555555
# define COLOR_CEILING         0x8888FF

/* ************************************************************************** */
/*                                 INCLUDES                                   */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/time.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include <limits.h>
# include <ctype.h>

# include "../mlx/mlx.h"
# include "../utils/GNL/get_next_line.h"
# include "../utils/Libft/libft.h"
# include "parser.h"

/* ************************************************************************** */
/*                               DATA STRUCTURES                              */
/* ************************************************************************** */

typedef struct s_rays
{
	int		start_x;
	int		start_y;
	int		tile_size;
	int		ray_length;
	int		rays_count;
	float	fov;
	float	angle_step;
	int		x0;
	int		y0;
}	t_rays;

typedef struct s_ray_data
{
	float	ray_dir_x;
	float	ray_dir_y;
	double	ray_x;
	double	ray_y;
	double	step_size;
	double	distance;
	int		map_x;
	int		map_y;
	char	cell;
	int		x1;
	int		y1;
}	t_ray_data;

typedef struct s_player_mmap
{
	int	start_x;
	int	start_y;
	int	tile_size;
	int	px;
	int	py;
	int	half;
}	t_player_mmap;

typedef struct s_tile
{
	int	sx;
	int	sy;
	int	tile_size;
	int	color;
}	t_tile;

typedef struct s_mmap
{
	int	map_w;
	int	map_h;
	int	start_x;
	int	start_y;
	int	tile_size;
}	t_mmap;

typedef struct s_door
{
	int		x;
	int		y;
	int		state;
	float	open_timer;
}	t_door;

typedef struct s_texture
{
	void	*img_ptr;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_length;
	int		endian;
}	t_texture;

typedef struct s_theme
{
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;
	t_texture	door;
	t_texture	sprite[7];
}	t_theme;

typedef struct s_ray
{
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		side;
	double	perp_wall_dist;
	char	hit_type;
}	t_ray;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
}	t_player;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef struct s_input
{
	bool	key_up;
	bool	key_down;
	bool	key_left;
	bool	key_right;
	bool	rotate_left;
	bool	rotate_right;
}	t_input;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			screen_w;
	int			screen_h;
	t_player	player;
	t_input		input;
	t_map		map;
	t_img		screen;
	t_theme		theme;
	t_door		*doors;
	int			door_count;
	double		last_time;
	double		frame_time;
	t_cub_p		*parsing;
}	t_game;

typedef struct s_line
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_line;

/* Minimaps / drawing helper payloads */
typedef struct s_tex_draw
{
	int			x;
	int			draw_start;
	int			draw_end;
	t_texture	*tex;
	int			tex_x;
	int			line_height;
	int			y;
	float		step;
	float		tex_pos;
	int			tex_y;
	char		*dst;
	int			color;
}	t_tex_draw;

typedef struct s_col
{
	int			line_height;
	int			draw_start;
	int			draw_end;
	t_texture	*tex;
	int			tex_x;
}	t_col;

typedef struct s_vline
{
	int	x;
	int	y1;
	int	y2;
	int	color;
}	t_vline;

typedef struct s_tile_line
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	color;
}	t_tile_line;

/* ************************************************************************** */
/*                              FUNCTION PROTOS                               */
/* ************************************************************************** */

/* init */
void			init_player(t_player *player, int x, int y, char dir);
void			init_input(t_input *input);
void			init_game(t_game *game, t_cub_p *cub);
void			img_init(t_game *game);
void			init_doors(t_game *game);
void			set_player_north(t_player *player);
void			set_player_south(t_player *player);
void			set_player_east(t_player *player);
void			set_player_west(t_player *player);
void			set_player_direction(t_player *player, char dir);
void			map_init(t_map *map, t_map_p *mapp);

/* handlers */
int				close_window(void);
int				handle_key_press(int keycode, t_game *game);
int				handle_key_release(int keycode, t_game *game);
int				mouse_move(int x, int y, void *param);
int				mouse_click(int button, int x, int y, void *param);
int				is_walkable(char c);

/* raycasting core */
int				render_frame(t_game *game);
void			set_pixel(t_game *game, int x, int y, int color);
void			update_doors(t_game *game);
t_door			*get_door_at(t_game *game, int x, int y);
t_ray			cast_ray_center(t_game *game);

void			calc_ray_dir(t_game *game, int x, t_ray *ray);
void			calc_step_side_dist(t_game *game, t_ray *ray);
void			perform_dda(t_game *game, t_ray *ray);
void			calc_perp_wall_dist(t_game *game, t_ray *ray);

t_texture		*select_texture(t_game *game, t_ray *ray);
int				calc_tex_x(t_game *game, t_ray *ray, t_texture *tex);
void			draw_textured_column(t_game *game, t_tex_draw d);
void			render_column(t_game *game, int x);

/* movement / timing */
void			update_player(t_game *game);
double			get_time(void);
void			rotate_left(t_game *game);
void			rotate_right(t_game *game);
void			strafe_left(t_game *game);
void			strafe_right(t_game *game);

/* textures / hud */
void			load_theme_textures(t_game *game, t_cub_p *cub);
char			*sanitize_path(const char *raw);
void			draw_crosshair(t_game *game);

/* minimap */
void			draw_minimap_border(t_game *game);
void			draw_minimap_map(t_game *game);
void			draw_minimap_player(t_game *game);
void			draw_minimap_rays(t_game *game);
unsigned int	color_to_hex(t_color_p color);
int				calc_tile_size(t_game *game);
double			get_player_angle(t_player *player);
void			draw_vertical_line(t_game *game, t_vline v);
void			draw_line(t_game *game, t_tile_line p);

/* cleaner */
void	game_cleanup_and_exit(t_game *g);
void	free_cub(t_cub_p *cub);
#endif