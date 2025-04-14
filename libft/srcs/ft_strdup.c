/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:28:10 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/14 14:09:29 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char		*dest;
	size_t		len;

	len = ft_strlen(src);
	dest = malloc(sizeof(char) * (len + 1));
	if (!(dest))
		return (NULL);
	ft_memcpy(dest, src, len + 1);
	return (dest);
}
