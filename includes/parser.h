/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:26:13 by mel-mora          #+#    #+#             */
/*   Updated: 2025/05/16 20:55:34 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}	t_texture;

typedef struct s_cub
{
	t_map		map;
	t_texture	texture;
	t_color		floor_color;
	t_color		ceiling_color;
}	t_cub;

t_cub	parse_map(char *filename);
int		hundle_color_texture(char *line, t_cub *cub, int *count);
t_color parse_color(char *line, int *error);
int		handle_color(char *line, t_cub *cub, int *color_count);
int		handle_texture(char *line, t_cub *cub, int *texture_count);;
void	intialize_map(t_cub *cub);
char	*skip_whitespace(char *line);
char	*trim_and_collapse_spaces(char *line);
int		hundle_map(char *line, t_cub *cub);
void    free_split(char **split);

# endif