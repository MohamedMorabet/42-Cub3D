/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:25:58 by mel-mora          #+#    #+#             */
/*   Updated: 2025/08/09 13:27:36 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	load_texture(t_game *game, t_texture *texture, char *path)
{
	char	*clean_path;

	clean_path = sanitize_path(path);
	texture->img_ptr = mlx_xpm_file_to_image(game->mlx, clean_path,
			&texture->width, &texture->height);
	if (!texture->img_ptr)
	{
		printf("Failed to load texture : %s", clean_path);
		free(clean_path);
		exit(EXIT_FAILURE);
	}
	free(clean_path);
	texture->addr = mlx_get_data_addr(texture->img_ptr, &texture->bpp,
			&texture->line_length, &texture->endian);
}

char	*sanitize_path(const char *raw)
{
	size_t	len;
	char	*clean;

	if (!raw)
		return (NULL);
	while (*raw && isspace((unsigned char)*raw))
		raw++;
	len = strlen(raw);
	while (len > 0 && isspace((unsigned char)raw[len - 1]))
		len--;
	clean = malloc(len + 1);
	if (!clean)
		return (NULL);
	memcpy(clean, raw, len);
	clean[len] = '\0';
	return (clean);
}

void	load_theme_textures(t_game *game, t_cub_p *cub)
{
	(void)cub;
	load_texture(game, &game->theme.sprite[0], "./sprites/1.xpm");
	load_texture(game, &game->theme.sprite[1], "./sprites/2.xpm");
	load_texture(game, &game->theme.sprite[2], "./sprites/3.xpm");
	load_texture(game, &game->theme.sprite[3], "./sprites/4.xpm");
	load_texture(game, &game->theme.sprite[4], "./sprites/5.xpm");
	load_texture(game, &game->theme.sprite[5], "./sprites/6.xpm");
	load_texture(game, &game->theme.sprite[6], "./sprites/7.xpm");
	load_texture(game, &game->theme.north, game->parsing->texture.north);
	load_texture(game, &game->theme.south, game->parsing->texture.south);
	load_texture(game, &game->theme.east, game->parsing->texture.east);
	load_texture(game, &game->theme.west, game->parsing->texture.west);
	load_texture(game, &game->theme.door, "./textures/door.xpm");
}
