#include "../includes/game.h"

static void	free_ptr(void **p)
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

static void	destroy_image(void *mlx, void **img_ptr)
{
	if (mlx && img_ptr && *img_ptr)
	{
		mlx_destroy_image(mlx, *img_ptr);
		*img_ptr = NULL;
	}
}

static void	destroy_texture(void *mlx, t_texture *t)
{
	if (!t)
		return ;
	destroy_image(mlx, &t->img_ptr);
}

static void	destroy_screen(void *mlx, t_img *scr)
{
	if (!scr)
		return ;
	destroy_image(mlx, &scr->img);
}

static void	destroy_theme(void *mlx, t_theme *th)
{
	if (!th)
		return ;
	destroy_texture(mlx, &th->north);
	destroy_texture(mlx, &th->south);
	destroy_texture(mlx, &th->east);
	destroy_texture(mlx, &th->west);
	destroy_texture(mlx, &th->door);
}

static void	free_doors(t_game *g)
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
	//free_map_grid(&g->map);
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
	/* Do not free g->mlx on macOS MiniLibX */
}

void	game_cleanup_and_exit(t_game *g)
{
	game_cleanup(g);
}
