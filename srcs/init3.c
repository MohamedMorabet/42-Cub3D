/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 12:53:58 by mel-mora          #+#    #+#             */
/*   Updated: 2025/08/09 12:56:40 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	set_player_north(t_player *player)
{
	player->dir_x = 0.0;
	player->dir_y = -1.0;
	player->plane_x = 0.6;
	player->plane_y = 0.0;
}

void	set_player_south(t_player *player)
{
	player->dir_x = 0.0;
	player->dir_y = 1.0;
	player->plane_x = -0.6;
	player->plane_y = 0.0;
}

void	set_player_east(t_player *player)
{
	player->dir_x = 1.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.6;
}

void	set_player_west(t_player *player)
{
	player->dir_x = -1.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = -0.6;
}

void	set_player_direction(t_player *player, char dir)
{
	if (dir == 'N')
		set_player_north(player);
	else if (dir == 'S')
		set_player_south(player);
	else if (dir == 'E')
		set_player_east(player);
	else if (dir == 'W')
		set_player_west(player);
}
