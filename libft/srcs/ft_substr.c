/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:09:04 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/13 19:54:03 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	j;
	
	if (!str)
		return (NULL);
	res = (char *)malloc(len + 1);
	if (!str || !(res))
		return (0);
	i = start;
	j = 0;
	while (i < ft_strlen(str) && j < len)
		res[j++] = s[i++];
	res[j] = '\0';
	return (res);
}
