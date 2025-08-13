/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 12:57:18 by mel-mora          #+#    #+#             */
/*   Updated: 2025/08/09 12:58:39 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	close_window(void)
{
	exit(0);
	return (0);
}

void	testing_print(t_cub_p *cub)
{
	int	i;

	printf("Floor color: R:%d G:%d B:%d\n", cub->floor_color.red,
		cub->floor_color.green, cub->floor_color.blue);
	printf("Ceiling color: R:%d G:%d B:%d\n", cub->ceiling_color.red,
		cub->ceiling_color.green, cub->ceiling_color.blue);
	printf("North texture: %s\n", cub->texture.north);
	printf("South texture: %s\n", cub->texture.south);
	printf("West texture: %s\n", cub->texture.west);
	printf("East texture: %s\n", cub->texture.east);
	printf("Map:\n");
	printf("Width: %d, Height: %d\n", cub->map.width, cub->map.height);
	i = 0;
	while (cub->map.grid[i])
	{
		printf("%s\n", cub->map.grid[i]);
		i++;
	}
	printf("Player position: X:%d Y:%d Direction:%c\n",
		cub->player.x, cub->player.y, cub->player.direction);
}

void check_leaks() {
	system("leaks Cub3D");
}

int	main(int argc, char **argv)
{
	atexit(check_leaks);
	t_cub_p	cub;
	t_game	game;

	if (argc != 2)
	{
		write(2, "Error\nUsage: ./cub3d <map.cub>\n", 32);
		return (1);
	}
	cub = parse_map(argv[1]);
	//testing_print(&cub);
	init_game(&game, &cub);
	img_init(&game);
	load_theme_textures(&game, &cub);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_hook(game.win, 2, 1L << 0, handle_key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, handle_key_release, &game);
	mlx_hook(game.win, 6, (1L << 6), mouse_move, &game);
	mlx_mouse_hook(game.win, mouse_click, &game);
	mlx_loop_hook(game.mlx, render_frame, &game);
	mlx_loop(game.mlx);
	return (0);
}
