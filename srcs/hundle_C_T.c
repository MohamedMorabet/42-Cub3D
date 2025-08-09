/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundle_C_T.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:24:42 by mel-mora          #+#    #+#             */
/*   Updated: 2025/05/30 17:10:32 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static char	*skip_leading_ws(char *line)
{
	char	*ptr;

	ptr = line;
	while (*ptr && isspace((unsigned char)*ptr))
		ptr++;
	return (ptr);
}

/*
 * Determine spec type by peeking at the first token **only if there's a space**
 * immediately after it:
 *   1-char "F"/"C" → SPEC_COLOR
 *   2-char "NO"/"SO"/"WE"/"EA" → SPEC_TEXTURE
 *   bad single char → ERR_COLOR_ID
 *   anything else → ERR_TEXTURE_ID
 * If there's no space at all, return -1 (not a spec).
 */
static int	get_spec_type(const char *ptr)
{
	const char	*space;
	size_t		id_len;

	space = strchr(ptr, ' ');
	if (!space)
		return (-1);
	id_len = (size_t)(space - ptr);
	if (id_len == 1)
	{
		if (ptr[0] == 'F' || ptr[0] == 'C')
			return (SPEC_COLOR);
		return (ERR_COLOR_ID);
	}
	if (id_len == 2)
	{
		if ((ptr[0] == 'N' && ptr[1] == 'O')
			|| (ptr[0] == 'S' && ptr[1] == 'O')
			|| (ptr[0] == 'W' && ptr[1] == 'E')
			|| (ptr[0] == 'E' && ptr[1] == 'A'))
			return (SPEC_TEXTURE);
		return (ERR_TEXTURE_ID);
	}
	return (ERR_TEXTURE_ID);
}

/*
 * Main handler—counters remain static locals.
 * Returns:
 *   0 on success,
 *   1 on generic error,
 *   2 invalid color id,
 *   3 invalid texture id,
 *  -1 not a spec line (map logic should take over).
 */
int	hundle_color_texture(char *line, t_cub_p *cub, int *count)
{
	char		*ptr;
	int			spec;

	ptr = skip_leading_ws(line);
	spec = get_spec_type(ptr);
	if (spec == ERR_COLOR_ID)
		return (ERR_COLOR_ID);
	if (spec == ERR_TEXTURE_ID)
		return (ERR_TEXTURE_ID);
	if (spec == SPEC_COLOR)
		return (handle_color(ptr, cub, count));
	if (spec == SPEC_TEXTURE)
		return (handle_texture(ptr, cub, count));
	return (-1);
}
