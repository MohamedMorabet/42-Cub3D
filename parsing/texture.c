/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:41:15 by mel-mora          #+#    #+#             */
/*   Updated: 2025/05/16 18:00:46 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	handle_texture(char *line, t_cub *cub, int *texture_count)
{
	line = trim_and_collapse_spaces(line);
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		if (cub->texture.north)
            return (1); // Already set
		cub->texture.north = ft_substr(line, 3, ft_strlen(line) - 3);
		(*texture_count)++;
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		if (cub->texture.south)
            return (1);
		cub->texture.south = ft_substr(line, 3, ft_strlen(line) - 3);
		(*texture_count)++;
	}
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		if (cub->texture.west)
			return (1);
		cub->texture.west = ft_substr(line, 3, ft_strlen(line) - 3);
		(*texture_count)++;
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		if (cub->texture.east)
            return (1);
		cub->texture.east = ft_substr(line, 3, ft_strlen(line) - 3);
		(*texture_count)++;
	}
	else
		return (3); // Invalid texture ID
	return (0);
}
