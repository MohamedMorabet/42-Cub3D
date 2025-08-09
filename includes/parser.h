/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:26:13 by mel-mora          #+#    #+#             */
/*   Updated: 2025/08/09 17:19:15 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/* ************************************************************************** */
/*                                   TYPES                                    */
/* ************************************************************************** */

typedef struct s_color_p
{
	int	red;
	int	green;
	int	blue;
}	t_color_p;

typedef struct s_map_p
{
	char	**grid;
	int		width;
	int		height;
}	t_map_p;

typedef struct s_texture_p
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}	t_texture_p;

typedef struct s_player_p
{
	int		x;
	int		y;
	char	direction;
}	t_player_p;

typedef struct s_cub_p
{
	t_map_p		map;
	t_texture_p	texture;
	t_color_p	floor_color;
	t_color_p	ceiling_color;
	t_player_p	player;
}	t_cub_p;

/* ************************************************************************** */
/*                                  MACROS                                    */
/* ************************************************************************** */

/* Return codes */
# define SPEC_COLOR      0
# define SPEC_TEXTURE    1
# define ERR_COLOR_ID    2
# define ERR_TEXTURE_ID  3

/* ************************************************************************** */
/*                               PROTOTYPES                                   */
/* ************************************************************************** */

t_cub_p		parse_map(char *filename);
int			parse_line(char *line, t_cub_p *cub, int *count);
int			hundle_color_texture(char *line, t_cub_p *cub, int *count);
t_color_p	parse_color(char *line, int *error);
int			handle_color(char *line, t_cub_p *cub, int *color_count);
int			handle_texture(char *line, t_cub_p *cub, int *texture_count);
void		intialize_map(t_cub_p *cub);
char		*skip_whitespace(char *line);
char		*trim_and_collapse_spaces(char *line);
int			hundle_map(char *line, t_cub_p *cub);
void		free_split(char **split);

/* checkers */
int			open_check(char *filename);
void		move_spaces_to_zero_p(char **grid, int height);
void		normalize_map(t_cub_p *cub);
int			check_positions(t_cub_p *cub);
int			check_line_1(char *line);
int			check_characters(char **grid, int height);
int			check_lines(char **grid, int height);
int			count_player_ps(char **grid, int height);
int			final_check(t_cub_p *cub, int count);
int			final_check2(t_cub_p *cub);
void		set_player_p_position(t_cub_p *cub);

#endif