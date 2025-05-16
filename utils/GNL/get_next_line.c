/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:31:17 by mel-mora          #+#    #+#             */
/*   Updated: 2024/11/21 16:13:01 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	didnt_reach_end(char *p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		if (p[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

static void	manage_buffer(char *p, int bytes_read)
{
	int	i;

	i = 0;
	while (p[bytes_read])
	{
		p[i] = p[bytes_read];
		i++;
		bytes_read++;
	}
	p[i] = '\0';
}

void	full_line(char *p, char **tmp, char **s)
{
	int		i;
	char	*tmp_s;

	i = 0;
	while (p[i] != '\n')
		i++;
	*tmp = ft_substr(p, 0, i + 1);
	manage_buffer(p, i + 1);
	tmp_s = ft_strjoin(*s, *tmp);
	free(*s);
	*s = tmp_s;
}

static int	handle_read_and_process(int fd, char *p, char **s)
{
	int		bytes_read;
	char	*tmp;

	if (p[0] == '\0')
	{
		bytes_read = read(fd, p, BUFFER_SIZE);
		if (bytes_read == -1)
			return (2);
		if (bytes_read <= 0)
			return (0);
		p[bytes_read] = '\0';
	}
	if (!didnt_reach_end(p))
	{
		full_line(p, &tmp, s);
		free(tmp);
		return (0);
	}
	tmp = ft_strjoin(*s, p);
	free(*s);
	*s = tmp;
	p[0] = '\0';
	return (1);
}

char	*get_next_line(int fd)
{
	char		*s;
	int			l;
	static char	p[BUFFER_SIZE + 1];

	s = NULL;
	l = 1;
	if (fd >= 0)
	{
		while (l)
		{
			l = handle_read_and_process(fd, p, &s);
			if (l == 2)
			{
				free (s);
				return (NULL);
			}
		}
	}
	return (s);
}
