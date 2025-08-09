/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:41:01 by mel-mora          #+#    #+#             */
/*   Updated: 2025/08/09 16:20:18 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

t_texture	*get_sprite_frame(t_theme *theme)
{
	static int				frame = 0;
	static struct timeval	last_time = {0};
	struct timeval			current_time;
	long					elapsed_ms;

	gettimeofday(&current_time, NULL);
	elapsed_ms = (current_time.tv_sec - last_time.tv_sec) * 1000
		+ (current_time.tv_usec - last_time.tv_usec) / 1000;
	if (elapsed_ms >= 500)
	{
		if (frame == 6)
			frame = 0;
		else
			frame = frame + 1;
		last_time = current_time;
	}
	return (&theme->sprite[frame]);
}

t_texture	*select_texture(t_game *game, t_ray *ray)
{
	if (ray->hit_type == 'D')
		return (&game->theme.door);
	else if (ray->hit_type == 'X')
		return (get_sprite_frame(&game->theme));
	else if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			return (&game->theme.west);
		else
			return (&game->theme.east);
	}
	else
	{
		if (ray->ray_dir_y > 0)
			return (&game->theme.north);
		else
			return (&game->theme.south);
	}
}

int	calc_tex_x(t_game *game, t_ray *ray, t_texture *tex)
{
	float	wall_x;
	int		tex_x;

	if (ray->side == 0)
		wall_x = game->player.pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = game->player.pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (float)tex->width);
	if ((ray->side == 0 && ray->ray_dir_x > 0)
		|| (ray->side == 1 && ray->ray_dir_y < 0))
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}
