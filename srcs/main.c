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

int	close_window(t_game	*game)
{
	game_cleanup(game);
	exit(0);
}

void	check_leaks(void)
{
	system("leaks Cub3D");
}

int	main(int argc, char **argv)
{
	t_cub_p	cub;
	t_game	game;

	atexit (check_leaks);
	if (argc != 2)
	{
		write(2, "Error\nUsage: ./cub3d <map.cub>\n", 32);
		return (1);
	}
	cub = parse_map(argv[1]);
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
