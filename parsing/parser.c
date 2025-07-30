/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:39:26 by mel-mora          #+#    #+#             */
/*   Updated: 2025/07/13 12:19:17 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	intialize_map(t_cub_p *cub)
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

static void	parse_config_lines(t_cub_p *cub, int fd)
{
	int		count;
	char	*line;

	count = 0;
	while (count < 6)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (parse_line(line, cub, &count) != 0)
		{
			free(line);
			close(fd);
			exit(EXIT_FAILURE);
		}
		free(line);
	}
	if (final_check(cub, count) != 0)
	{
		close(fd);
		exit(EXIT_FAILURE);
	}
}

static char	*skip_empty_lines(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

static void	parse_map_lines(t_cub_p *cub, int fd, char *line)
{
	while (line && line[0] != '\n')
	{
		if (hundle_map(line, cub) != 0)
		{
			free(line);
			close(fd);
			exit(EXIT_FAILURE);
		}
		free(line);
		line = get_next_line(fd);
	}
	if (line && line[0] == '\n')
	{
		free(line);
		close(fd);
		free_split(cub->map.grid);
		exit(write(2, "Error\nInvalid map\n", 18));
	}
	if (final_check2(cub) != 0)
	{
		close(fd);
		free_split(cub->map.grid);
		exit(EXIT_FAILURE);
	}
	close(fd);
}

t_cub_p	parse_map(char *filename)
{
	t_cub_p	cub;
	int		fd;
	char	*line;

	intialize_map(&cub);
	fd = open_check(filename);
	parse_config_lines(&cub, fd);
	line = skip_empty_lines(fd);
	parse_map_lines(&cub, fd, line);
	set_player_p_position(&cub);
	return (cub);
}
