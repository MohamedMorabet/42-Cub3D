/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:58:08 by mel-mora          #+#    #+#             */
/*   Updated: 2025/08/13 11:58:09 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	free_ptr(void **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
	}
}

void	free_cub(t_cub_p *cub)
{
	int	i;

	if (!cub)
		return ;
	if (cub->map.grid)
	{
		i = 0;
		while (i < cub->map.height)
		{
			free_ptr((void **)&cub->map.grid[i]);
			i++;
		}
		free_ptr((void **)&cub->map.grid);
	}
	free_ptr((void **)&cub->texture.north);
	free_ptr((void **)&cub->texture.south);
	free_ptr((void **)&cub->texture.west);
	free_ptr((void **)&cub->texture.east);
}

void	destroy_image(void *mlx, void **img_ptr)
{
	if (mlx && img_ptr && *img_ptr)
	{
		mlx_destroy_image(mlx, *img_ptr);
		*img_ptr = NULL;
	}
}

void	destroy_texture(void *mlx, t_texture *t)
{
	if (!t)
		return ;
	destroy_image(mlx, &t->img_ptr);
}
