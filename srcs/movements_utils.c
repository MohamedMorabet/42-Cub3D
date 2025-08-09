/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:14:16 by mel-mora          #+#    #+#             */
/*   Updated: 2025/08/09 13:19:52 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	strafe_left(t_game *game)
{
	double	move;
	double	next_x;
	double	next_y;

	move = BASE_MOVE_STEP * game->frame_time;
	next_x = game->player.pos_x - game->player.plane_x * move;
	next_y = game->player.pos_y - game->player.plane_y * move;
	if (is_walkable(game->map.grid[(int)next_y][(int)game->player.pos_x]))
		game->player.pos_y = next_y;
	if (is_walkable(game->map.grid[(int)game->player.pos_y][(int)next_x]))
		game->player.pos_x = next_x;
}

void	strafe_right(t_game *game)
{
	double	move;
	double	next_x;
	double	next_y;

	move = BASE_MOVE_STEP * game->frame_time;
	next_x = game->player.pos_x + game->player.plane_x * move;
	next_y = game->player.pos_y + game->player.plane_y * move;
	if (is_walkable(game->map.grid[(int)next_y][(int)game->player.pos_x]))
		game->player.pos_y = next_y;
	if (is_walkable(game->map.grid[(int)game->player.pos_y][(int)next_x]))
		game->player.pos_x = next_x;
}

void	rotate_left(t_game *game)
{
	double	rot;
	double	old_dir_x;
	double	old_plane_x;

	rot = BASE_ROT_STEP * game->frame_time;
	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	game->player.dir_x = game->player.dir_x * cos(-rot)
		- game->player.dir_y * sin(-rot);
	game->player.dir_y = old_dir_x * sin(-rot)
		+ game->player.dir_y * cos(-rot);
	game->player.plane_x = game->player.plane_x * cos(-rot)
		- game->player.plane_y * sin(-rot);
	game->player.plane_y = old_plane_x * sin(-rot)
		+ game->player.plane_y * cos(-rot);
}

void	rotate_right(t_game *game)
{
	double	rot;
	double	old_dir_x;
	double	old_plane_x;

	rot = BASE_ROT_STEP * game->frame_time;
	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	game->player.dir_x = game->player.dir_x * cos(rot)
		- game->player.dir_y * sin(rot);
	game->player.dir_y = old_dir_x * sin(rot)
		+ game->player.dir_y * cos(rot);
	game->player.plane_x = game->player.plane_x * cos(rot)
		- game->player.plane_y * sin(rot);
	game->player.plane_y = old_plane_x * sin(rot)
		+ game->player.plane_y * cos(rot);
}
