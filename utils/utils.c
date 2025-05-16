/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:29:37 by mel-mora          #+#    #+#             */
/*   Updated: 2025/05/16 15:22:00 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

char	*skip_whitespace(char *line)
{
	while (*line && (*line == ' ' || *line == '\t'))
		line++;
	return (line);
}

char	*trim_and_collapse_spaces(char *line)
{
	char	*new;
	int		i = 0, j = 0;
	int		in_space = 1;

	if (!line)
		return (NULL);

	// First, allocate worst-case: same length as input + 1
	new = malloc(sizeof(char) * (ft_strlen(line) + 1));
	if (!new)
		return (NULL);

	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
		{
			if (!in_space) // first space after word
			{
				new[j++] = ' ';
				in_space = 1;
			}
		}
		else
		{
			new[j++] = line[i];
			in_space = 0;
		}
		i++;
	}

	// Remove trailing space if any
	if (j > 0 && new[j - 1] == ' ')
		j--;

	new[j] = '\0';
	return (new);
}

