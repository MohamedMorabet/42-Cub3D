/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:29:37 by mel-mora          #+#    #+#             */
/*   Updated: 2025/05/30 17:04:48 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

char	*skip_whitespace(char *line)
{
	while (*line && (*line == ' ' || *line == '\t'))
		line++;
	return (line);
}

void	check_space(int *in_space, char *new, int *j)
{
	if (*in_space == 0)
	{
		new[*j] = ' ';
		(*j)++;
		*in_space = 1;
	}
}

void	intilize_vars(int *i, int *j, int *in_space)
{
	*i = 0;
	*j = 0;
	*in_space = 1;
}

char	*trim_and_collapse_spaces(char *line)
{
	char	*new;
	int		i;
	int		j;
	int		in_space;

	intilize_vars(&i, &j, &in_space);
	if (!line)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen(line) + 1));
	if (!new)
		return (NULL);
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
			check_space(&in_space, new, &j);
		else
		{
			new[j++] = line[i];
			in_space = 0;
		}
		i++;
	}
	if (j > 0 && new[j - 1] == ' ')
		j--;
	return (new[j] = '\0', new);
}
