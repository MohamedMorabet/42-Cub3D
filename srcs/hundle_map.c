/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:08:59 by mel-mora          #+#    #+#             */
/*   Updated: 2025/05/30 17:08:20 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	check_line(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '1' || map[i] == '0' || map[i] == ' ')
		{
			i++;
		}
		else
		{
			printf("map[%d]: %s\n", i, map);
			printf("Error\nInvalid character in map\n");
			exit(1);
		}
	}
}

char	*replace_spaces_with_zero(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			line[i] = '0';
		i++;
	}
	return (line);
}

int	hundle_map(char *line, t_cub_p *cub)
{
	char	*trimmed;
	size_t	len;
	char	**new_grid;

	trimmed = ft_strtrim_newline(line);
	if (!trimmed)
		return (1);
	new_grid = realloc(cub->map.grid,
			sizeof(char *) * (cub->map.height + 2));
	if (!new_grid)
	{
		free(trimmed);
		return (1);
	}
	cub->map.grid = new_grid;
	cub->map.grid[cub->map.height] = trimmed;
	cub->map.height++;
	len = ft_strlen(trimmed);
	if ((int)len > cub->map.width)
		cub->map.width = (int)len;
	cub->map.grid[cub->map.height] = NULL;
	return (0);
}
