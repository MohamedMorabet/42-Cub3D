/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 12:48:55 by mel-mora          #+#    #+#             */
/*   Updated: 2025/08/09 12:53:40 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	init_game(t_game *game, t_cub_p *cub)
{
	game->screen_w = WIN_W;
	game->screen_h = WIN_H;
	game->parsing = cub;
	init_player(&game->player, cub->player.x, cub->player.y,
		cub->player.direction);
	init_input(&game->input);
	map_init(&game->map, &cub->map);
	game->mlx = mlx_init();
	if (!game->mlx)
		exit(EXIT_FAILURE);
	game->win = mlx_new_window(game->mlx, game->screen_w,
			game->screen_h, "Cub3D");
	if (!game->win)
		exit(EXIT_FAILURE);
	init_doors(game);
}

void	img_init(t_game *game)
{
	game->screen.img = mlx_new_image(game->mlx, game->screen_w, game->screen_h);
	game->screen.addr = mlx_get_data_addr(game->screen.img, &game->screen.bpp,
			&game->screen.size_line, &game->screen.endian);
}

static int	count_doors(t_game *game)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == 'D')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

static void	initialize_doors(t_game *game)
{
	int	x;
	int	y;
	int	idx;

	y = 0;
	idx = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == 'D')
			{
				game->doors[idx].x = x;
				game->doors[idx].y = y;
				game->doors[idx].state = 0;
				game->doors[idx].open_timer = 0.0f;
				idx++;
			}
			x++;
		}
		y++;
	}
}

void	init_doors(t_game *game)
{
	int	count;

	count = count_doors(game);
	game->door_count = count;
	game->doors = malloc(sizeof(t_door) * count);
	if (!game->doors)
		exit(EXIT_FAILURE);
	initialize_doors(game);
}
