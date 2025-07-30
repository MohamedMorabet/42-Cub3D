/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:27:22 by mel-mora          #+#    #+#             */
/*   Updated: 2025/05/30 17:12:09 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

t_color_p	parse_color(char *line, int *error)
{
	int		i;
	char	**rgb_values;
	t_color_p	color;

	color.red = -1;
	color.green = -1;
	color.blue = -1;
	rgb_values = ft_split(line, ',');
	if (!rgb_values)
		return (color);
	i = 0;
	while (rgb_values[i])
	{
		if (i == 0)
			color.red = ft_atoi(rgb_values[i], error, 0);
		else if (i == 1)
			color.green = ft_atoi(rgb_values[i], error, 0);
		else if (i == 2)
			color.blue = ft_atoi(rgb_values[i], error, 0);
		i++;
	}
	free_split(rgb_values);
	return (color);
}

int	is_color_set(t_color_p color)
{
	return (color.red != -1 || color.green != -1 || color.blue != -1);
}

int	check_color(t_color_p color)
{
	if (color.red < 0 || color.red > 255
		|| color.green < 0 || color.green > 255
		|| color.blue < 0 || color.blue > 255)
		return (1);
	return (0);
}

int	handle_color(char *line, t_cub_p *cub, int *color_count)
{
	int	error;

	error = 0;
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		if (is_color_set(cub->floor_color))
			return (1);
		cub->floor_color = parse_color(line + 2, &error);
		if (check_color(cub->floor_color) == 1 || error == 1)
			return (2);
		(*color_count)++;
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		if (is_color_set(cub->ceiling_color))
			return (1);
		cub->ceiling_color = parse_color(line + 2, &error);
		if (check_color(cub->ceiling_color) == 1 || error == 1)
			return (2);
		(*color_count)++;
	}
	else
		return (10);
	return (0);
}
