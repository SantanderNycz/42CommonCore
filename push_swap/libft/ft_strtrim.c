/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:43:22 by lsantand          #+#    #+#             */
/*   Updated: 2025/07/06 18:43:23 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	isinset(int c, const char *set)
{
	char	character;

	character = (char)c;
	while (*set)
	{
		if (*set++ == character)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(const char *str, const char *set)
{
	char	*new_str;
	int		start;
	int		end;
	int		i;

	start = 0;
	end = ft_strlen(str);
	while (str[start] && isinset(str[start], set))
		start++;
	while (end > start && isinset(str[end - 1], set))
		end--;
	new_str = malloc(end - start + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (start < end)
		new_str[i++] = str[start++];
	new_str[i] = '\0';
	return (new_str);
}
