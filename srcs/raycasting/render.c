/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:41:53 by mel-mora          #+#    #+#             */
/*   Updated: 2025/08/09 17:05:25 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static void	setup_column(t_game *game, int x, t_ray *ray, t_col *c)
{
	int	tmp;

	(void)x;
	tmp = (int)(game->screen_h / ray->perp_wall_dist);
	c->line_height = tmp;
	tmp = -c->line_height / 2 + game->screen_h / 2;
	c->draw_start = tmp;
	if (c->draw_start < 0)
		c->draw_start = 0;
	tmp = c->line_height / 2 + game->screen_h / 2;
	c->draw_end = tmp;
	if (c->draw_end > game->screen_h)
		c->draw_end = game->screen_h;
	c->tex = select_texture(game, ray);
	c->tex_x = calc_tex_x(game, ray, c->tex);
}

static t_tex_draw	build_tex_draw(int x, t_col *c)
{
	t_tex_draw	d;

	d.x = x;
	d.draw_start = c->draw_start;
	d.draw_end = c->draw_end;
	d.tex = c->tex;
	d.tex_x = c->tex_x;
	d.line_height = c->line_height;
	return (d);
}

static t_vline	make_vline(int x, int y1, int y2, int color)
{
	t_vline	v;

	v.x = x;
	v.y1 = y1;
	v.y2 = y2;
	v.color = color;
	return (v);
}

void	render_column(t_game *game, int x)
{
	t_ray		ray;
	t_col		c;
	t_tex_draw	d;

	calc_ray_dir(game, x, &ray);
	calc_step_side_dist(game, &ray);
	perform_dda(game, &ray);
	calc_perp_wall_dist(game, &ray);
	setup_column(game, x, &ray, &c);
	draw_vertical_line(game, make_vline(x, 0, c.draw_start,
			color_to_hex(game->parsing->ceiling_color)));
	draw_vertical_line(game, make_vline(x, c.draw_end, game->screen_h,
			color_to_hex(game->parsing->floor_color)));
	d = build_tex_draw(x, &c);
	draw_textured_column(game, d);
}

t_ray	cast_ray_center(t_game *game)
{
	t_ray	ray;
	int		center_x;

	center_x = game->screen_w / 2;
	calc_ray_dir(game, center_x, &ray);
	calc_step_side_dist(game, &ray);
	perform_dda(game, &ray);
	calc_perp_wall_dist(game, &ray);
	return (ray);
}
