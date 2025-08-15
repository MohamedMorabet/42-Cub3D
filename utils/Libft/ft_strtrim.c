/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:12:01 by mel-mora          #+#    #+#             */
/*   Updated: 2025/08/15 21:49:20 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*result;

	if (!s1 || !set)
	{
		if (s1 && !set)
			return ((char *)s1);
		return (NULL);
	}
	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] != '\0' && ft_strchr(set, s1[i]) != NULL)
		i++;
	while (j == 0 && ft_strchr(set, s1[j]) != NULL)
		j--;
	if (i > j)
		return (ft_strdup(""));
	result = ft_substr(s1, i, j - i + 1);
	return (result);
}

char	*ft_strtrim_newline(char const *s1)
{
	size_t	len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	if (len > 0 && s1[len - 1] == '\n')
		return (ft_substr(s1, 0, len - 1));
	return (ft_strdup(s1));
}
