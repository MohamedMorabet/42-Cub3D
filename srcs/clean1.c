#include "../includes/game.h"

static void	free_ptr(void **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
	}
}

static void	free_map_p_grid(t_map_p *map)
{
	if (!map || !map->grid)
		return;

	if (map->height > 0)
	{
		for (int i = 0; i < map->height; ++i)
			free_ptr((void **)&map->grid[i]);
	}
	else
	{
		/* Fallback: if height isn't set, free until NULL row */
		for (int i = 0; map->grid[i]; ++i)
			free_ptr((void **)&map->grid[i]);
	}
	free_ptr((void **)&map->grid);
}

static void	free_textures(t_texture_p *tex)
{
	if (!tex) return;
	free_ptr((void **)&tex->north);
	free_ptr((void **)&tex->south);
	free_ptr((void **)&tex->west);
	free_ptr((void **)&tex->east);
}

/* Public API: call this when you're done with `t_cub_p` contents */
void	free_cub(t_cub_p *cub)
{
	if (!cub) return;

	free_map_p_grid(&cub->map);
	free_textures(&cub->texture);

	/* Colors and player hold no heap pointers; nothing else to free. */
	/* Optionally zero structs if you want a fully reset state: */
	// cub->floor_color = (t_color_p){0,0,0};
	// cub->ceiling_color = (t_color_p){0,0,0};
	// cub->player = (t_player_p){0,0,0};
}

/* Optional helper if you malloc'ed `t_cub_p *cub = malloc(sizeof(*cub))` */

// static void	free_map_grid(t_map *m)
// {
// 	int	i;

// 	if (!m || !m->grid)
// 		return ;
// 	i = 0;
// 	while (i < m->height)
// 	{
// 		free_ptr((void **)&m->grid[i]);
// 		i++;
// 	}
// 	free_ptr((void **)&m->grid);
// 	m->width = 0;
// 	m->height = 0;
// }

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
