/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:42:18 by mel-mora          #+#    #+#             */
/*   Updated: 2025/08/09 15:42:45 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

int	render_frame(t_game *game)
{
	int		x;
	double	current_time;

	x = 0;
	current_time = get_time();
	game->frame_time = current_time - game->last_time;
	game->last_time = current_time;
	update_player(game);
	update_doors(game);
	while (x < game->screen_w)
	{
		render_column(game, x);
		x++;
	}
	draw_crosshair(game);
	draw_minimap_map(game);
	draw_minimap_player(game);
	draw_minimap_rays(game);
	mlx_put_image_to_window(game->mlx, game->win, game->screen.img, 0, 0);
	return (0);
}
