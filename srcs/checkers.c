/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:50:37 by mel-mora          #+#    #+#             */
/*   Updated: 2025/05/30 17:16:12 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	final_check(t_cub_p *cub, int count)
{
	if (cub->texture.north == NULL || cub->texture.south == NULL
		|| cub->texture.west == NULL || cub->texture.east == NULL)
	{
		printf("Error\nMissing texture\n");
		return (1);
	}
	if (cub->floor_color.red == -1 || cub->ceiling_color.red == -1)
	{
		printf("Error\nMissing color\n");
		return (1);
	}
	if (count == 0)
	{
		printf("Error\nEmpty map\n");
		return (1);
	}
	return (0);
}

int	final_check2(t_cub_p *cub)
{
	if (cub->map.grid == NULL)
		return (printf("Error\nInvalid map\n"), 1);
	if (cub->map.width == 0 || cub->map.height == 0)
	{
		return (printf("Error\nEmpty map\n"), 1);
	}
	if (check_lines(cub->map.grid, cub->map.height) != 0)
		return (printf("Error\nInvalid line\n"), 1);
	if (count_player_ps(cub->map.grid, cub->map.height) != 1)
	{
		printf("Error\nInvalid number of player positions\n");
		return (1);
	}
	if (check_positions(cub) != 0)
		return (printf("Error\nMap not closed\n"), 1);
	return (0);
}
