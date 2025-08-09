/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_norm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 12:23:07 by mel-mora          #+#    #+#             */
/*   Updated: 2025/08/09 13:29:12 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

unsigned int	color_to_hex(t_color_p color)
{
	if (color.red < 0)
		color.red = 0;
	if (color.red > 255)
		color.red = 255;
	if (color.green < 0)
		color.green = 0;
	if (color.green > 255)
		color.green = 255;
	if (color.blue < 0)
		color.blue = 0;
	if (color.blue > 255)
		color.blue = 255;
	return ((color.red << 16) | (color.green << 8) | color.blue);
}

// from draw_utils.c
static void	update_single_door(t_game *game, t_door *door)
{
	int	px;
	int	py;

	if (door->state == 1)
	{
		door->open_timer += game->frame_time;
		if (door->open_timer >= DOOR_OPEN_TIME)
		{
			px = (int)game->player.pos_x;
			py = (int)game->player.pos_y;
			if (px == door->x && py == door->y)
				door->open_timer = 0.0f;
			else
			{
				door->state = 0;
				game->map.grid[door->y][door->x] = 'D';
			}
		}
	}
}

void	update_doors(t_game *game)
{
	int		i;
	t_door	*door;

	i = 0;
	while (i < game->door_count)
	{
		door = &game->doors[i];
		update_single_door(game, door);
		i++;
	}
}
