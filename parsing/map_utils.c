/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:52:37 by mel-mora          #+#    #+#             */
/*   Updated: 2025/05/30 15:01:47 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	fill_line(char *new_line, char *old_line, int width)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(old_line);
	while (i < width)
	{
		if (i < len)
			new_line[i] = old_line[i];
		else
			new_line[i] = ' ';
		i++;
	}
	new_line[width] = '\0';
}

void	normalize_map(t_cub_p *cub)
{
	int		i;
	char	*new_line;

	if (!cub || !cub->map.grid)
		return ;
	i = 0;
	while (i < cub->map.height)
	{
		new_line = malloc(cub->map.width + 1);
		if (!new_line)
			exit(EXIT_FAILURE);
		fill_line(new_line, cub->map.grid[i], cub->map.width);
		free(cub->map.grid[i]);
		cub->map.grid[i] = new_line;
		i++;
	}
}
