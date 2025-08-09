/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 12:45:41 by mel-mora          #+#    #+#             */
/*   Updated: 2025/08/09 12:48:30 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	handle_key_press(int keycode, t_game *game)
{
	if (keycode == W || keycode == Z)
		game->input.key_up = true;
	else if (keycode == S)
		game->input.key_down = true;
	else if (keycode == A || keycode == Q)
		game->input.key_left = true;
	else if (keycode == D)
		game->input.key_right = true;
	else if (keycode == LEFT)
		game->input.rotate_left = true;
	else if (keycode == RIGHT)
		game->input.rotate_right = true;
	else if (keycode == ESC)
		exit(0);
	return (0);
}

int	handle_key_release(int keycode, t_game *game)
{
	if (keycode == W || keycode == Z)
		game->input.key_up = false;
	else if (keycode == S)
		game->input.key_down = false;
	else if (keycode == A || keycode == Q)
		game->input.key_left = false;
	else if (keycode == D)
		game->input.key_right = false;
	else if (keycode == LEFT)
		game->input.rotate_left = false;
	else if (keycode == RIGHT)
		game->input.rotate_right = false;
	return (0);
}

int	mouse_move(int x, int y, void *param)
{
	static int	last_x = -1;
	t_game		*game;
	double		sensitivity;
	double		delta_x;

	(void)y;
	game = (t_game *)param;
	sensitivity = 0.03;
	if (last_x == -1)
		last_x = x;
	delta_x = (double)(x - last_x);
	last_x = x;
	if (delta_x == 0)
		return (0);
	game->frame_time = fabs(delta_x) * sensitivity / BASE_ROT_STEP;
	if (delta_x > 0)
		rotate_right(game);
	else
		rotate_left(game);
	return (0);
}

int	mouse_click(int button, int x, int y, void *param)
{
	t_game	*game;
	t_ray	ray;
	t_door	*door;

	(void)x;
	(void)y;
	game = (t_game *)param;
	if (button == 1)
	{
		ray = cast_ray_center(game);
		if (ray.hit_type == 'D')
		{
			door = get_door_at(game, ray.map_x, ray.map_y);
			if (door && door->state == 0)
			{
				door->state = 1;
				door->open_timer = 0.0f;
				game->map.grid[door->y][door->x] = '0';
			}
		}
	}
	return (0);
}
