/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:41:27 by mel-mora          #+#    #+#             */
/*   Updated: 2025/08/09 17:05:05 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

void	draw_textured_column(t_game *game, t_tex_draw d)
{
	d.step = (float)d.tex->height / (float)d.line_height;
	d.tex_pos = (d.draw_start - game->screen_h / 2
			+ d.line_height / 2) * d.step;
	d.y = d.draw_start;
	while (d.y < d.draw_end)
	{
		d.tex_y = (int)d.tex_pos & (d.tex->height - 1);
		d.tex_pos += d.step;
		d.dst = d.tex->addr
			+ (d.tex_y * d.tex->line_length + d.tex_x * (d.tex->bpp / 8));
		d.color = *(unsigned int *)d.dst;
		set_pixel(game, d.x, d.y, d.color);
		d.y++;
	}
}

void	draw_vertical_line(t_game *game, t_vline v)
{
	int	y;

	if (v.y1 < 0)
		v.y1 = 0;
	if (v.y2 > game->screen_h)
		v.y2 = game->screen_h;
	y = v.y1;
	while (y < v.y2)
	{
		set_pixel(game, v.x, y, v.color);
		y++;
	}
}
