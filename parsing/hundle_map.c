/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:08:59 by mel-mora          #+#    #+#             */
/*   Updated: 2025/05/16 20:28:57 by mel-mora         ###   ########.fr       */
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

int	hundle_map(char *line, t_cub *cub)
{
    // int		i;
    char	**map;

    line = trim_and_collapse_spaces(line);
    if (ft_strchr(line, '1') != NULL)
    {
        map = ft_split(line, '\n');
        if (!map)
            return (1);
        check_line(map[0]);
        cub->map.grid = map;
        cub->map.height++;
        if (cub->map.width < (int)ft_strlen(line))
            cub->map.width = ft_strlen(line);
    }
    else
        return (0);
    return (0);
}