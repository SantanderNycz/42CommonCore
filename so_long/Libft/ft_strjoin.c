/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 12:22:46 by lsantand          #+#    #+#             */
/*   Updated: 2025/09/02 19:30:00 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	int		i;
	char	*value;

	i = 0;
	value = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * (sizeof(char)));
	if (!value)
		return (0);
	while (s1[i])
	{
		value[i] = s1[i];
		i++;
	}
	while (s2[i - ft_strlen(s1)])
	{
		value[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	value[ft_strlen(s1) + ft_strlen(s2)] = 0;
	free(s1);
	return (value);
}
