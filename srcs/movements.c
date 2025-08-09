/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:05:39 by mel-mora          #+#    #+#             */
/*   Updated: 2025/08/09 13:20:26 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	is_walkable(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static void	move_forward(t_game *game)
{
	double	move;
	double	next_x;
	double	next_y;

	move = BASE_MOVE_STEP * game->frame_time;
	next_x = game->player.pos_x + game->player.dir_x * move;
	next_y = game->player.pos_y + game->player.dir_y * move;
	if (is_walkable(game->map.grid[(int)next_y][(int)game->player.pos_x]))
		game->player.pos_y = next_y;
	if (is_walkable(game->map.grid[(int)game->player.pos_y][(int)next_x]))
		game->player.pos_x = next_x;
}

static void	move_backward(t_game *game)
{
	double	move;
	double	next_x;
	double	next_y;

	move = BASE_MOVE_STEP * game->frame_time;
	next_x = game->player.pos_x - game->player.dir_x * move;
	next_y = game->player.pos_y - game->player.dir_y * move;
	if (is_walkable(game->map.grid[(int)next_y][(int)game->player.pos_x]))
		game->player.pos_y = next_y;
	if (is_walkable(game->map.grid[(int)game->player.pos_y][(int)next_x]))
		game->player.pos_x = next_x;
}

void	update_player(t_game *game)
{
	if (game->input.key_up)
		move_forward(game);
	if (game->input.key_down)
		move_backward(game);
	if (game->input.key_left)
		strafe_left(game);
	if (game->input.key_right)
		strafe_right(game);
	if (game->input.rotate_left)
		rotate_left(game);
	if (game->input.rotate_right)
		rotate_right(game);
}
