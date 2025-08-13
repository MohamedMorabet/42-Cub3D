/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:50:39 by mel-mora          #+#    #+#             */
/*   Updated: 2025/08/13 11:58:07 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	destroy_screen(void *mlx, t_img *scr)
{
	if (!scr)
		return ;
	destroy_image(mlx, &scr->img);
}

void	destroy_theme(void *mlx, t_theme *th)
{
	if (!th)
		return ;
	destroy_texture(mlx, &th->north);
	destroy_texture(mlx, &th->south);
	destroy_texture(mlx, &th->east);
	destroy_texture(mlx, &th->west);
	destroy_texture(mlx, &th->door);
}

void	free_doors(t_game *g)
{
	if (!g)
		return ;
	free_ptr((void **)&g->doors);
	g->door_count = 0;
}

void	game_cleanup(t_game *g)
{
	if (!g)
		return ;
	destroy_theme(g->mlx, &g->theme);
	destroy_screen(g->mlx, &g->screen);
	free_doors(g);
	if (g->parsing)
	{
		free_cub(g->parsing);
		g->parsing = NULL;
	}
	if (g->mlx && g->win)
	{
		mlx_destroy_window(g->mlx, g->win);
	}
}
