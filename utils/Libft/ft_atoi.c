/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:34:30 by mel-mora          #+#    #+#             */
/*   Updated: 2025/05/30 16:40:02 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	avoid_space(const char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] != '\0' && str[i] != '\n')
		return (1);
	return (0);
}

int	ft_atoi(const char *str, int *error, int i)
{
	int				sign;
	long			result;

	result = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && - result < INT_MIN))
			return (*error = 1, 0);
	}
	if (avoid_space(str, i))
		return (*error = 1, 0);
	return ((int)(result * sign));
}
