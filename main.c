/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:23:49 by mel-mora          #+#    #+#             */
/*   Updated: 2025/05/30 17:23:09 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub.h"

void	testing_print(t_cub *cub)
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
}

int	main(int argc, char **argv)
{
	t_cub	cub;

	if (argc != 2)
	{
		write(2, "Error\nUsage: ./cub3d <map.cub>\n", 32);
		return (1);
	}
	cub = parse_map(argv[1]);
	testing_print(&cub);
	// Initialize the game and start the main loop
	// ...
	return (0);
}
