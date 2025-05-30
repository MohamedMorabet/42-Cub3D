/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:49:01 by mel-mora          #+#    #+#             */
/*   Updated: 2025/05/30 17:15:07 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	is_invalid_position(t_cub *cub, size_t i, size_t j)
{
	size_t	curr_len;
	size_t	prev_len;
	size_t	next_len;

	curr_len = ft_strlen(cub->map.grid[i]);
	prev_len = ft_strlen(cub->map.grid[i - 1]);
	next_len = ft_strlen(cub->map.grid[i + 1]);
	if (i == 0 || i + 1 >= (size_t)cub->map.height || j == 0
		|| j + 1 >= curr_len || j >= prev_len || j >= next_len
		|| cub->map.grid[i - 1][j] == ' '
		|| cub->map.grid[i + 1][j] == ' '
		|| cub->map.grid[i][j - 1] == ' '
		|| cub->map.grid[i][j + 1] == ' ')
		return (1);
	return (0);
}

int	check_positions(t_cub *cub)
{
	size_t	i;
	size_t	j;
	size_t	len;

	normalize_map(cub);
	i = 1;
	while (i < (size_t)cub->map.height)
	{
		len = ft_strlen(cub->map.grid[i]);
		j = 0;
		while (j < len)
		{
			if (cub->map.grid[i][j] != '1' && cub->map.grid[i][j] != ' ')
			{
				if (is_invalid_position(cub, i, j))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_line_1(char *line)
{
	size_t	i;

	if (line == NULL || line[0] == '\0')
		return (1);
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1' && line[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	check_middle_line(char *line)
{
	size_t	j;
	size_t	len;

	j = 0;
	while (line[j] == ' ')
		j++;
	if (line[j] == '\0')
		return (1);
	len = ft_strlen(line);
	if (line[j] != '1' || line[len - 1] != '1')
		return (1);
	return (0);
}

int	check_lines(char **grid, int height)
{
	int		i;

	if (check_line_1(grid[0]) != 0)
		return (1);
	if (check_line_1(grid[height - 1]) != 0)
		return (1);
	i = 1;
	while (i < height - 1)
	{
		if (!grid[i] || check_middle_line(grid[i]) != 0)
			return (1);
		i++;
	}
	if (check_characters(grid, height) != 0)
		return (1);
	return (0);
}
