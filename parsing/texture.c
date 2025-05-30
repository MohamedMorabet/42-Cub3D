/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:41:15 by mel-mora          #+#    #+#             */
/*   Updated: 2025/05/30 17:07:00 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	assign_texture(char **dest, char *line, int *count)
{
	if (*dest)
		return (1);
	*dest = ft_substr(line, 3, ft_strlen(line) - 3);
	(*count)++;
	return (0);
}

int	handle_texture(char *line, t_cub *cub, int *texture_count)
{
	line = trim_and_collapse_spaces(line);
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (assign_texture(&cub->texture.north, line, texture_count));
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (assign_texture(&cub->texture.south, line, texture_count));
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (assign_texture(&cub->texture.west, line, texture_count));
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (assign_texture(&cub->texture.east, line, texture_count));
	return (3);
}
