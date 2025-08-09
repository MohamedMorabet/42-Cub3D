/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:22:44 by mel-mora          #+#    #+#             */
/*   Updated: 2025/08/09 15:22:53 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

// draw_minimap_player
typedef struct s_player_mmap
{
	int	start_x;
	int	start_y;
	int	tile_size;
	int	px;
	int	py;
	int	half;
}	t_player_mmap;

static void	draw_player_square(t_game *game, int px, int py, int half)
{
	int	x;
	int	y;

	y = py - half;
	while (y <= py + half)
	{
		x = px - half;
		while (x <= px + half)
		{
			if (x >= 0 && x < game->screen_w
				&& y >= 0 && y < game->screen_h)
				set_pixel(game, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
}

void	draw_minimap_player(t_game *game)
{
	t_player_mmap	v;

	v.start_x = MINIMAP_OFFSET_X;
	v.start_y = MINIMAP_OFFSET_Y;
	v.tile_size = calc_tile_size(game);
	v.px = (int)(game->player.pos_x * v.tile_size) + v.start_x;
	v.py = (int)(game->player.pos_y * v.tile_size) + v.start_y;
	v.half = PLAYER_SIZE / 2;
	draw_player_square(game, v.px, v.py, v.half);
}
