/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:09:04 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/15 18:19:37 by lsantand         ###   ########.fr       */
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
	if (start >= ft_strlen(str))
		return (ft_strdup(""));
	res = (char *)malloc(len + 1);
	if (!(res))
		return (NULL);
	i = start;
	j = 0;
	while (str[i] && j < len)
		res[j++] = str[i++];
	res[j] = '\0';
	return (res);
}
