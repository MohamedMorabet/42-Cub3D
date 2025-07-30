/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_helpers2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:52:27 by mel-mora          #+#    #+#             */
/*   Updated: 2025/05/30 15:07:19 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

// Function to open a file and check the .cub extension
int	open_check(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nopening file");
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(filename + ft_strlen(filename) - 4, ".cub", 4) != 0)
	{
		close(fd);
		printf("Error\nFile is not a .cub file\n");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	move_spaces_to_zero(char **grid, int height)
{
	int		i;
	int		j;
	size_t	len;

	i = 0;
	while (i < height)
	{
		len = ft_strlen(grid[i]);
		j = 0;
		while (j < (int)len)
		{
			if (grid[i][j] == ' ')
				grid[i][j] = '0';
			j++;
		}
		i++;
	}
}

int	count_player_ps(char **grid, int height)
{
	int		player_count;
	int		i;
	int		j;
	size_t	len;

	player_count = 0;
	i = 0;
	while (i < height)
	{
		len = ft_strlen(grid[i]);
		j = 0;
		while (j < (int)len)
		{
			if (grid[i][j] == 'N' || grid[i][j] == 'S' ||
				grid[i][j] == 'E' || grid[i][j] == 'W')
				player_count++;
			j++;
		}
		i++;
	}
	return (player_count);
}

int	check_characters(char **grid, int height)
{
	int		i;
	int		j;
	size_t	len;

	i = 0;
	while (i < height)
	{
		len = ft_strlen(grid[i]);
		j = 0;
		while (j < (int)len)
		{
			if (grid[i][j] != '0' && grid[i][j] != '1' &&
				grid[i][j] != ' ' && grid[i][j] != 'N' &&
				grid[i][j] != 'S' && grid[i][j] != 'E' &&
				grid[i][j] != 'W')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
