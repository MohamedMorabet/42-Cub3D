/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:39:26 by mel-mora          #+#    #+#             */
/*   Updated: 2025/05/16 20:02:31 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	intialize_map(t_cub *cub)
{
	cub->map.grid = NULL;
	cub->map.width = 0;
	cub->map.height = 0;
	cub->texture.north = NULL;
	cub->texture.south = NULL;
	cub->texture.west = NULL;
	cub->texture.east = NULL;
	cub->floor_color.red = -1;
	cub->floor_color.green = -1;
	cub->floor_color.blue = -1;
	cub->ceiling_color.red = -1;
	cub->ceiling_color.green = -1;
	cub->ceiling_color.blue = -1;
}

int	parse_line(char *line, t_cub *cub, int *count)
{
	int		res;

	res = hundle_color_texture(line, cub, count);
	if (res != 0)
	{
		if (res == 1)
			return (printf("Error\nA duplicate texture or color was found\n"), 1); // Already set
		else if (res == 2 || res == 3)
			return (printf("Error\nInvalid texture/color\n"), 2); // Invalid color
		else if (res == 4)
			return (printf("Error\nInvalid line\n"), 4); // Invalid line
		else if (res == 5)
			return (printf("Error\nToo many textures\n"), 5);
	}
	
	return (0);
}

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

int	final_check(t_cub *cub, int count)
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

t_cub	parse_map(char *filename)
{
	t_cub	cub;
	int		fd;
	char	*line;
	int count;

	intialize_map(&cub);
	fd = open_check(filename);

	// hundle 
	count = 0;
	while ((line = get_next_line(fd)) != NULL && count < 6)
	{
		if (parse_line(line, &cub, &count) != 0)
		{
			free(line);
			close(fd);
			exit(EXIT_FAILURE);
		}
		free(line);
	}
	if (final_check(&cub, count) != 0)
	{
		close(fd);
		exit(EXIT_FAILURE);
	}

	// hundle map
	while ((line = get_next_line(fd)) != NULL)
	{
		if (hundle_map(line, &cub) != 0)
		{
			free(line);
			close(fd);
			exit(EXIT_FAILURE);
		}
		free(line);
	}
	close(fd);
	return (cub);
}
