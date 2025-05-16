/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:08:59 by mel-mora          #+#    #+#             */
/*   Updated: 2025/05/16 21:28:00 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void    check_line(char *map)
{
    int i;

    i = 0;
    while (map[i])
    {
        if (map[i] == '1' || map[i] == '0' || map[i] == ' ')
        {
            i++;
        }
        else
        {
            printf("map[%d]: %s\n", i, map);
            printf("Error\nInvalid character in map\n");
            exit(1);
        }
    }
}

// int	hundle_map(char *line, t_cub *cub)
// {
//     static int		i = 0;
//     char	**map;

//     line = trim_and_collapse_spaces(line);
//     if (ft_strchr(line, '1') != NULL)
//     {
//         map = ft_split(line, '\n');
//         if (!map)
//             return (1);
//         // check_line(map[0]);
//         cub->map.grid[i++] = map[0];
//         cub->map.height++;
//         if (cub->map.width < (int)ft_strlen(line))
//             cub->map.width = ft_strlen(line);
//     }
//     else
//         return (0);
//     return (0);
// }

int hundle_map(char *line, t_cub *cub)
{
    char    *trimmed;
    size_t  len;
    char    **new_grid;

    /* Trim spaces + remove trailing newline */
    trimmed = trim_and_collapse_spaces(line);
    if (!trimmed)
        return (1);
    len = strlen(trimmed);
    if (len > 0 && trimmed[len - 1] == '\n')
        trimmed[len - 1] = '\0';

    /* Skip non-map lines */
    if (ft_strchr(trimmed, '1') == NULL)
    {
        free(trimmed);
        printf("Error\nInvalid map\n");
        return (1);
    }

    /* Grow grid safely */
    new_grid = realloc(cub->map.grid,
        sizeof(char *) * (cub->map.height + 1));
    if (!new_grid)
    {
        free(trimmed);
        /* cub->map.grid still valid */
        return (1);
    }
    cub->map.grid = new_grid;

    /* Store row and update dims */
    cub->map.grid[cub->map.height] = trimmed;
    cub->map.height += 1;
    if ((int)ft_strlen(trimmed) > cub->map.width)
        cub->map.width = ft_strlen(trimmed);

    return (0);
}
