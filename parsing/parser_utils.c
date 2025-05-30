/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:18:14 by mel-mora          #+#    #+#             */
/*   Updated: 2025/05/30 17:07:43 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	parse_line(char *line, t_cub *cub, int *count)
{
	int		res;

	res = hundle_color_texture(line, cub, count);
	if (res != 0)
	{
		if (res == 1)
			return (printf("Error\nA duplicate texture or"
					" color was found\n"), 1);
		else if (res == 2 || res == 3)
			return (printf("Error\nInvalid texture/color\n"), 2);
		else if (res == 4)
			return (printf("Error\nInvalid line\n"), 4);
		else if (res == 5)
			return (printf("Error\nToo many textures\n"), 5);
	}
	return (0);
}
