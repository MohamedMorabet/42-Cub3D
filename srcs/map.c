/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:00:42 by mel-mora          #+#    #+#             */
/*   Updated: 2025/08/09 13:01:04 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	map_init(t_map *map, t_map_p *mapp)
{
	map->grid = mapp->grid;
	map->width = mapp->width;
	map->height = mapp->height;
}
