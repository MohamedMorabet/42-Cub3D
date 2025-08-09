/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 12:19:25 by mel-mora          #+#    #+#             */
/*   Updated: 2025/07/13 12:25:04 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	set_player_p_position(t_cub_p *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub->map.height)
	{
		j = 0;
		while (j < cub->map.width)
		{
			if (cub->map.grid[i][j] == 'N' || cub->map.grid[i][j] == 'S' ||
				cub->map.grid[i][j] == 'E' || cub->map.grid[i][j] == 'W')
			{
				cub->player.x = j;
				cub->player.y = i;
				cub->player.direction = cub->map.grid[i][j];
				return ;
			}
			j++;
		}
		i++;
	}
}
