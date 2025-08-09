/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 12:51:15 by mel-mora          #+#    #+#             */
/*   Updated: 2025/08/09 12:56:47 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	init_player(t_player *player, int x, int y, char dir)
{
	player->pos_x = x + 0.5;
	player->pos_y = y + 0.5;
	player->move_speed = 0.05;
	player->rot_speed = 0.05;
	set_player_direction(player, dir);
}

void	init_input(t_input *input)
{
	input->key_up = false;
	input->key_down = false;
	input->key_left = false;
	input->key_right = false;
	input->rotate_left = false;
	input->rotate_right = false;
}
