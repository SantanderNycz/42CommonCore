/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:43:41 by lsantand          #+#    #+#             */
/*   Updated: 2025/07/06 18:43:42 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*st;
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	st = malloc(size + 1);
	if (!st)
		return (0);
	ft_strlcpy(st, s, size + 1);
	while (i < size)
	{
		st[i] = (*f)(i, st[i]);
		i++;
	}
	return (st);
}
