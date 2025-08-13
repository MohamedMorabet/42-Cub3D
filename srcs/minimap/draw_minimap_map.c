/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:21:05 by mel-mora          #+#    #+#             */
/*   Updated: 2025/08/09 15:30:05 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static int	get_tile_color(char tile)
{
	if (tile == '1')
		return (0x333333);
	if (tile == 'X')
		return (0x5fcc25);
	if (tile == 'D')
		return (0x996633);
	return (0xFFFFFF);
}

static void	draw_tile(t_game *game, t_tile t)
{
	int	px;
	int	py;

	py = 0;
	while (py < t.tile_size)
	{
		px = 0;
		while (px < t.tile_size)
		{
			set_pixel(game, t.sx + px, t.sy + py, t.color);
			px++;
		}
		py++;
	}
}

void	draw_minimap_map(t_game *game)
{
	t_mmap	v;
	t_tile	t;
	int		x;
	int		y;

	v.map_w = game->map.width;
	v.map_h = game->map.height;
	v.start_x = MINIMAP_OFFSET_X;
	v.start_y = MINIMAP_OFFSET_Y;
	v.tile_size = calc_tile_size(game);
	y = 0;
	while (y < v.map_h)
	{
		x = 0;
		while (x < v.map_w)
		{
			t.sx = v.start_x + x * v.tile_size;
			t.sy = v.start_y + y * v.tile_size;
			t.tile_size = v.tile_size;
			t.color = get_tile_color(game->map.grid[y][x]);
			draw_tile(game, t);
			x++;
		}
		y++;
	}
}
