/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_rays.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:23:03 by mel-mora          #+#    #+#             */
/*   Updated: 2025/08/09 16:00:03 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static void	init_ray_data(t_ray_data *d, t_game *game, float angle)
{
	d->ray_dir_x = cosf(angle);
	d->ray_dir_y = sinf(angle);
	d->ray_x = game->player.pos_x;
	d->ray_y = game->player.pos_y;
	d->step_size = 0.05;
	d->distance = 0.0;
}

static t_tile_line	create_line_params(t_rays *r, t_ray_data *d)
{
	t_tile_line	p;

	p.x0 = r->x0;
	p.y0 = r->y0;
	p.x1 = (int)(d->ray_x * r->tile_size) + r->start_x;
	p.y1 = (int)(d->ray_y * r->tile_size) + r->start_y;
	p.color = 0x00FF00;
	return (p);
}

static void	trace_ray(t_game *game, t_rays *r, float angle)
{
	t_ray_data	d;
	int			hit;

	init_ray_data(&d, game, angle);
	hit = 0;
	while (!hit && d.distance < (r->ray_length / (double)r->tile_size))
	{
		d.ray_x += d.ray_dir_x * d.step_size;
		d.ray_y += d.ray_dir_y * d.step_size;
		d.distance += d.step_size;
		d.map_x = (int)d.ray_x;
		d.map_y = (int)d.ray_y;
		if (d.map_x < 0 || d.map_y < 0
			|| d.map_x >= game->map.width || d.map_y >= game->map.height)
			break ;
		d.cell = game->map.grid[d.map_y][d.map_x];
		if (d.cell == '1' || d.cell == 'D' || d.cell == 'S')
			hit = 1;
	}
	draw_line(game, create_line_params(r, &d));
}

void	draw_minimap_rays(t_game *game)
{
	t_rays	r;
	int		i;
	float	ray_angle;

	r.start_x = MINIMAP_OFFSET_X;
	r.start_y = MINIMAP_OFFSET_Y;
	r.tile_size = calc_tile_size(game);
	r.ray_length = 50;
	r.rays_count = 60;
	r.fov = 60 * (M_PI / 180);
	r.angle_step = r.fov / r.rays_count;
	r.x0 = (int)(game->player.pos_x * r.tile_size) + r.start_x;
	r.y0 = (int)(game->player.pos_y * r.tile_size) + r.start_y;
	i = 0;
	while (i < r.rays_count)
	{
		ray_angle = get_player_angle(&game->player)
			- r.fov / 2 + i * r.angle_step;
		trace_ray(game, &r, ray_angle);
		i++;
	}
}
