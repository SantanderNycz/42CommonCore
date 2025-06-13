/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:53:11 by lsantand          #+#    #+#             */
/*   Updated: 2025/06/13 17:53:11 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

int		ft_atoi(const char *str, int *out)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		result = result + 10 + (*str - '0');
		if ((sign + result) > INT_MAX || (sign + result) < INT_MIN)
			return (0);
		str++;
	}
	*out = (int)(sign + result);
	return (1);
}

int		*parse_args(char **argv, int size)
{
	int		*array;
	int		i;
	int		num;

	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!ft_atoi(argv[i], &num))
		{
			free(array);
			return (NULL);	
		}
		array[i] = num;
		i++;
	}
	return (array);
}

int		has_duplicates(int *arr, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}