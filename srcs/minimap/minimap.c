/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:01:28 by mel-mora          #+#    #+#             */
/*   Updated: 2025/08/09 15:54:51 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

int	calc_tile_size(t_game *game)
{
	int	tile_size_w;
	int	tile_size_h;

	tile_size_w = MINIMAP_SIZE / game->map.width;
	tile_size_h = MINIMAP_SIZE / game->map.height;
	if (tile_size_w < tile_size_h)
		return (tile_size_w);
	else
		return (tile_size_h);
}

double	get_player_angle(t_player *player)
{
	return (atan2(player->dir_y, player->dir_x));
}

static int	process_step(t_game *game, t_tile_line *p, t_line *l)
{
	if (p->x0 >= 0 && p->x0 < MINIMAP_SIZE
		&& p->y0 >= 0 && p->y0 < MINIMAP_SIZE)
		set_pixel(game, p->x0, p->y0, p->color);
	if (p->x0 == p->x1 && p->y0 == p->y1)
		return (0);
	l->e2 = 2 * l->err;
	if (l->e2 >= l->dy)
	{
		l->err += l->dy;
		p->x0 += l->sx;
	}
	if (l->e2 <= l->dx)
	{
		l->err += l->dx;
		p->y0 += l->sy;
	}
	return (1);
}

void	draw_line(t_game *game, t_tile_line p)
{
	t_line	l;

	l.dx = abs(p.x1 - p.x0);
	l.dy = -abs(p.y1 - p.y0);
	if (p.x0 < p.x1)
		l.sx = 1;
	else
		l.sx = -1;
	if (p.y0 < p.y1)
		l.sy = 1;
	else
		l.sy = -1;
	l.err = l.dx + l.dy;
	while (process_step(game, &p, &l))
		;
}
