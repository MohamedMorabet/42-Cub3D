/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 12:23:17 by mel-mora          #+#    #+#             */
/*   Updated: 2025/08/09 17:01:32 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	set_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= game->screen_w || y < 0 || y >= game->screen_h)
		return ;
	dst = game->screen.addr + (y * game->screen.size_line + x
			* (game->screen.bpp / 8));
	*(unsigned int *)dst = color;
}

double	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec + tv.tv_usec / 1000000.0);
}

void	draw_crosshair(t_game *game)
{
	const int	size = 10;
	const int	color = 0xFF0000;
	int			center_x;
	int			center_y;
	int			i;

	center_x = game->screen_w / 2;
	center_y = game->screen_h / 2;
	i = -size;
	while (i <= size)
	{
		set_pixel(game, center_x + i, center_y, color);
		i++;
	}
	i = -size;
	while (i <= size)
	{
		set_pixel(game, center_x, center_y + i, color);
		i++;
	}
}

t_door	*get_door_at(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < game->door_count)
	{
		if (game->doors[i].x == x && game->doors[i].y == y)
			return (&game->doors[i]);
		i++;
	}
	return (NULL);
}
